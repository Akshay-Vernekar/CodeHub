/*
 *  Problem-1 Implement Stack using Linked List.
 */

#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
    T data;
    struct Node* next;
    Node(T data):data(data),next(NULL){}
};

template<class T>
class stack
{
    private:
    Node<T>* head;
    
    public:
    stack():head(NULL){}
    
    T top()
    {
		if(head!=NULL)
			return head->data;
        cout << "Stack is empty" << endl;
		return (T)0;
    }
    
    void push(T val)
    {
        Node<T>* tmp = new Node<T>(val);
		if(head!=NULL)
			tmp->next = head;
        head = tmp;
        
    }
    void pop()
    {
        if(head==NULL)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
	
	void display()
	{
		Node<T>* tmp = head;
		while(tmp)
		{
			cout << tmp->data << " ";
			tmp=tmp->next;
		}
		cout << endl;
	}
};

template<typename T>
void TestFunction(T first,T second, T third)
{
	stack<T> st;
	cout << "TOP: ";
	st.top();
	cout << "POP: ";
	st.pop();
	cout << "Pushing " << first << endl;
	st.push(first);
	cout << "TOP: " << st.top() << endl;
	cout << "Pushing " << second << endl;
    st.push (second);
    cout << "Top: "	<< st.top () << endl;
	cout << "Pushing" << third << endl;
	st.push(third);
	cout << "Top: " << st.top () << endl;

	cout << "Displaying the Contents" << endl ;
	st.display ();
	cout << "Calling POP ... " << endl;
	st.pop ();
	cout << "TOP: " << st.top() << endl;
	cout << "Calling POP ... " << endl;
	st.pop ();
	cout << "Top: "<< st.top () << endl;
	cout << "Calling POP ... " << endl;
	st.pop ();
	cout<< "TOP: " << st.top() << endl;
	cout<< "Calling POP ... " <<endl;
    st.pop();	
	cout << "TOP: " << st.top () << endl;
	cout << "Calling POP ... " << endl;
	st.pop();
	
}

int main()
{
   cout << "****** INT************" << endl;
   TestFunction<int> (100,200,300);
   cout << "****** CHAR ***********"<< endl;
   TestFunction<char> ('A','B','C');
   cout << "******* STR ***********" << endl;
   TestFunction<string>("Hi","Hello","Hey"); 
   
   return 0;
}