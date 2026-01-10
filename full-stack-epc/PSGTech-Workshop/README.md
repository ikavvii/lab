# Flask Key-Value Store

A full-stack application with a Flask backend and modern web frontend for managing key-value pairs stored in JSON.

## Project Structure

```
PSGTech-Workshop/
├── docker-compose.yml      # Docker Compose orchestration
├── Jenkinsfile             # Jenkins CI/CD pipeline
├── JENKINS.md              # Jenkins setup documentation
├── backend/
│   ├── app.py              # Flask application
│   ├── requirements.txt    # Python dependencies
│   ├── Dockerfile          # Docker configuration
│   ├── .dockerignore       # Docker ignore file
│   └── data.json          # JSON data storage
└── frontend/
    ├── index.html          # Main HTML page
    ├── style.css           # Modern UI styling
    ├── script.js           # JavaScript for API calls
    ├── Dockerfile          # Docker configuration
    ├── nginx.conf          # Nginx server config
    └── .dockerignore       # Docker ignore file
```

## Quick Start

### 1. Start the Backend

Navigate to the backend folder and install dependencies:
```bash
cd backend
pip install -r requirements.txt
```

Run the Flask server:
```bash
python app.py
```

The backend API will start on `http://localhost:5000`

### 2. Open the Frontend

Open the frontend in your browser:
```bash
# From the project root directory
open frontend/index.html
```

Or simply open `frontend/index.html` in your web browser.

The UI will automatically connect to the backend at `http://localhost:5000`.

## Running with Docker

### Docker Compose (Recommended)

The easiest way to run both frontend and backend together:

1. From the project root directory, run:
```bash
docker-compose up --build
```

2. Access the application:
   - **Frontend:** http://localhost:8080
   - **Backend API:** http://localhost:5000

3. To run in detached mode (background):
```bash
docker-compose up -d
```

4. To stop the containers:
```bash
docker-compose down
```

5. To view logs:
```bash
docker-compose logs -f
```

### Backend with Docker

1. Build the Docker image:
```bash
cd backend
docker build -t flask-kvstore-backend .
```

2. Run the container:
```bash
docker run -p 5000:5000 flask-kvstore-backend
```

3. (Optional) Run with persistent data storage:
```bash
docker run -p 5000:5000 -v $(pwd)/data.json:/app/data.json flask-kvstore-backend
```

### Frontend with Docker

1. Build the Docker image:
```bash
cd frontend
docker build -t flask-kvstore-frontend .
```

2. Run the container:
```bash
docker run -p 8080:80 flask-kvstore-frontend
```

The frontend will be available at `http://localhost:8080`

### Run Both with Docker (Manual)

**Terminal 1 - Backend:**
```bash
cd backend
docker build -t flask-kvstore-backend .
docker run -p 5000:5000 flask-kvstore-backend
```

**Terminal 2 - Frontend:**
```bash
cd frontend
docker build -t flask-kvstore-frontend .
docker run -p 8080:80 flask-kvstore-frontend
```

Then open `http://localhost:8080` in your browser.

## Using the Application

### Web Interface

The frontend provides a beautiful, intuitive interface with:
- **Add/Update entries**: Enter a key and value to store data
- **Search**: Find specific entries by key
- **View all entries**: See all stored key-value pairs
- **Delete entries**: Remove individual entries with confirmation

### Features
- 🎨 Modern, gradient UI design
- ⚡ Real-time API integration
- 🔍 Instant search functionality
- 🗑️ Easy deletion with confirmation
- 🔄 Auto-refresh capabilities
- 📱 Responsive mobile design
- 🎯 Toast notifications for all actions

## CI/CD Pipeline

This project includes a complete Jenkins CI/CD pipeline for automated building, testing, and deployment.

### Pipeline Features

- **Automated Builds**: Automatically builds Docker images for both frontend and backend
- **Automated Testing**: Runs health checks and API tests on every build
- **Multi-Environment**: Supports staging and production deployments
- **Manual Approval**: Production deployments require manual approval
- **Docker Registry**: Pushes images to Docker Hub or private registry
- **Branch Strategy**: 
  - `main` → Production deployment (with approval)
  - `develop` → Staging deployment (automatic)
  - Feature branches → Build and test only

### Pipeline Stages

1. **Checkout** - Pull latest code
2. **Validate** - Check project structure
3. **Build Backend** - Create backend Docker image
4. **Build Frontend** - Create frontend Docker image
5. **Test Backend** - Run API tests
6. **Test Frontend** - Verify frontend accessibility
7. **Push to Registry** - Push images to Docker registry (main branch)
8. **Deploy to Staging** - Auto-deploy to staging (develop branch)
9. **Deploy to Production** - Manual approval deploy (main branch)

### Quick Setup

1. Configure Jenkins with required plugins (Docker, Pipeline, Git)
2. Create credentials for Docker registry
3. Create a new Pipeline job pointing to this repository
4. Set Script Path to `Jenkinsfile`

For detailed setup instructions, see **[JENKINS.md](JENKINS.md)**

## API Endpoints

### 1. Home - Get API Information
```bash
GET /
```

### 2. Set Key-Value Pair(s)
```bash
POST /set
Content-Type: application/json

{
  "key1": "value1",
  "key2": "value2"
}
```

**Example:**
```bash
curl -X POST http://localhost:5000/set \
  -H "Content-Type: application/json" \
  -d '{"name": "John", "age": "30"}'
```

### 3. Get Value by Key
```bash
GET /get/<key>
```

**Example:**
```bash
curl http://localhost:5000/get/name
```

### 4. Get All Key-Value Pairs
```bash
GET /all
```

**Example:**
```bash
curl http://localhost:5000/all
```

### 5. Delete a Key
```bash
DELETE /delete/<key>
```

**Example:**
```bash
curl -X DELETE http://localhost:5000/delete/name
```

## Data Storage

All data is stored in `data.json` in the same directory as the application.
