// main.cpp

#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    st.pop();
    st.pop();
    st.pop();

    cout << st.peek() << endl;

    return 0;
}
