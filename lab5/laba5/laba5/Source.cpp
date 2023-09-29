#include <iostream>
#include <stack>

using namespace std;

void main()
{
    setlocale(LC_ALL, "Rus");

    string str;
    stack <char> st;

    int nachalo = 0, end = 0;

    cout << "������� ������: " << endl;
    cin >> str;

    for (auto c : str)
    {
        if (c == '(' || c == '[' || c == '{')
            nachalo++;

        if (c == ')' || c == '}' || c == ']')
            end++;
    }

    if (nachalo != end)
        cout << "�������� ����������� �������" << endl;

    else

    {
        for (auto c : str)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);

            if (c == ')' || c == '}' || c == ']')
            {
                if (c == ')' && st.top() == '(')
                    st.pop();

                else

                    if (c == ']' && st.top() == '[')
                        st.pop();

                    else

                        if (c == '}' && st.top() == '{')
                            st.pop();

                        else
                        {
                            cout << "�������� ����������� �������" << endl;
                            exit(0);
                        }
            }
        }
        cout << "�������� ����������� �����" << endl;
    }
}