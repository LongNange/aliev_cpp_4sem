#include <stdio.h>

class Stack {
    int *m_data;
    int m_size;
    int m_pt;

public:
    Stack(int size)
    {
        m_size = size;
        m_data = new int [m_size];
        m_pt = 0;
    }

    ~Stack()
    {
        delete [] m_data;
    }

    int pop(void)
    {
        if(m_pt)
            return m_data[--m_pt];
        else
            return 0;
    }

    void push(int a)
    {
        if(m_pt >= m_size-1)
        {
            int *tmp = new int [m_size];
            tmp = m_data;
            m_size = 10 + 2 * m_size;
            m_data = new int [m_size];
            for (int i = 0; i<m_pt;i++)
            {
                m_data[i] = tmp[i];
            }
            delete [] tmp;
        }
        m_data[m_pt++] = a;
    }

    int empty()
    {
        return (m_pt == 0);
    }
};

int main()
{
    Stack s(3);
    while(!feof(stdin)) {
        int c = getchar();
        int x;
        switch (c)
        {
            case EOF: break;
            case '\n':
            case ' ' : break;
            case '=' : printf("Result = %d\n", s.pop()); break;
            case '+' : s.push(s.pop() + s.pop()); break;
            case '-' : s.push(-s.pop() + s.pop()); break;
            case '*' : s.push(s.pop() * s.pop()); break;
            case '/' : s.push(s.pop() / s.pop()); break;
            default:
                ungetc(c, stdin);
                if(scanf("%d", &x) != 1) {
                    fprintf(stderr, "Can't read integer\n");
                    return -1;
                } else {
                    s.push(x);
                }
                break;
        }
    }
};
