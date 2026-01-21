#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl;

    st.pop();

    cout << st.top() << endl;

    st.pop();

    cout << st.top() << endl;

    cout << st.size() << endl;
    st.pop();

    if (st.empty()) {
        cout << "Empty" << endl;
    } else {
        cout << st.top() << endl;
    }

    cout << st.size() << endl;

    

    return 0;
}