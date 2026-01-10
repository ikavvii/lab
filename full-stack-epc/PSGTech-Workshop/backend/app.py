from flask import Flask, request, jsonify
from flask_cors import CORS
import json
import os

app = Flask(__name__)
CORS(app)

DATA_FILE = 'data.json'

def load_data():
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, 'r') as f:
            return json.load(f)
    return {}

def save_data(data):
    with open(DATA_FILE, 'w') as f:
        json.dump(data, f, indent=4)

@app.route('/')
def home():
    return jsonify({
        'message': 'Flask Key-Value Store API',
        'endpoints': {
            'GET /': 'This help message',
            'POST /set': 'Set a key-value pair (JSON body: {"key": "value"})',
            'GET /get/<key>': 'Get value for a specific key',
            'GET /all': 'Get all key-value pairs',
            'DELETE /delete/<key>': 'Delete a specific key'
        }
    })

@app.route('/set', methods=['POST'])
def set_value():
    try:
        data = load_data()
        request_data = request.get_json()
        
        if not request_data:
            return jsonify({'error': 'No JSON data provided'}), 400
        
        for key, value in request_data.items():
            data[key] = value
        
        save_data(data)
        return jsonify({
            'message': 'Key-value pair(s) stored successfully',
            'data': request_data
        }), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/get/<key>', methods=['GET'])
def get_value(key):
    try:
        data = load_data()
        if key in data:
            return jsonify({
                'key': key,
                'value': data[key]
            }), 200
        else:
            return jsonify({'error': f'Key "{key}" not found'}), 404
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/all', methods=['GET'])
def get_all():
    try:
        data = load_data()
        return jsonify(data), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/delete/<key>', methods=['DELETE'])
def delete_value(key):
    try:
        data = load_data()
        if key in data:
            del data[key]
            save_data(data)
            return jsonify({
                'message': f'Key "{key}" deleted successfully'
            }), 200
        else:
            return jsonify({'error': f'Key "{key}" not found'}), 404
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)
