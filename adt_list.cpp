// adt_list.cpp

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
// don't #include anything else!

using namespace std;

class List_stack : public Stack //Reference made from lecture code by Toby Donaldson
{
private:
    class Node 
    {
    public:
        string str;
        Node* next;
    };

    Node* first = nullptr;
public:
    // default constructor makes an empty stack
    List_stack()  { }

    // destructor: deleting all nodes on the list is required unlike vectors that have it built into them
    ~List_stack() 
    {
        pop_all();
    }

    // Pre-condition:
    //    none
    // Post-condition:
    //    returns true if the stack is empty, and false otherwise

    //Code can also be found on lecture samples from Toby Donaldson
    bool is_empty() const 
    { 
        return first == nullptr; 
    }

     // Pre-condition:
    //    none
    // Post-condition:
    //    returns the number of elements in this stack
    int size() const
    {
    	int index = 0;

    	Node* start = first;

    	while(start != NULL)
    	{
    		index++;
    		start = start -> next;
    	}
    	return index;
    }

    // Pre-condition:
    //    none
    // Post-condition:
    //    puts x on the top of the stack
    void push(const string& x) 
    {
        first = new Node{x, first};
    }

     // Pre-condition:
    //    none
    // Post-condition:
    //    pushes all the elements of v onto the stack; first v[0] is pushed,
    //    then v[1], etc.
    void push(const vector<string>& v)
    {
 		int index = 0;

    	for(index = 0; index < v.size(); index++)
    	{
    		first = new Node{v[index], first};
    	}
    }
    // Pre-condition:
    //    none
    // Post-condition:
    //    if x occurs anywhere on the stack, then does nothing; otherwise,
    //    pushes x onto the stack
    void push_new(const string& s)
    {
    	int index = 0;
    	Node* var = first;
    	var = var -> next;

    	if(!first) //In case it's full
    	{
    		exit(1);
    	}

    	for(index = 0; index < size(); index++)
    	{
    		if(var -> str == s)
    		{

    		}
    		else
    		{
    			 first = new Node{s, first};
    		}
    	}
    }

    // Pre-condition:
    //    !is_empty()
    // Post-condition: 
    //   removes and returns the top element of the stack

    //Code can also be found on lecture samples from Toby Donaldson
    string pop() 
    {
        string outcome = first->str;
        Node* var = first;
        first = first->next;
        delete var;
        return outcome;
    }

     // Pre-condition:
    //    none
    // Post-condition: 
    //    if n <= 0, an empty vector is returned; otherwise, pops the first n items 
    //    off the stack and returns them in a vector such that the first item of the vector
    //    is the top of the stack, the second item of the vector is the second item of the
    ///   stack, and so on; if n > size(), then all items are popped and returned
    vector<string> pop(int n)
    {
    	if(n <= 0)
    	{
    		return vector<string>();
    	}
    	else
    	{
    		if(n > size())
    		{
    			pop_all();
    		}
    	}
    	
    	return pop(n);
    }

    // Pre-condition:
    //    !is_empty()
    // Post-condition: 
    //   returns a copy of the top element of the stack 
    //   (without removing it)
    string peek() const 
    {
        return first->str;
    }

}; // class List_stack

int main() 
{
	List_stack s;
	vector<string> temp1;
    assert(s.is_empty());

    s.push("yes");
    assert(!s.is_empty());
    assert(s.peek() == "yes");
    s.push("Power");
    s.push("To");
    s.push("People");
    s.size();
    cout << "Size is: " << s.size() << endl; //To check if size function works
    assert(s.size() == 4);
    assert(s.peek() == "People");
    s.pop();
    s.pop();
    s.pop();
    
    string top = s.pop();
    assert(top == "yes");
    assert(s.is_empty());

    cout << "\n****Push testing with vector as parameter\n" << endl;
    //Testing push function of vectors
    s.push("There are");
    temp1.push_back("Interested");
    temp1.push_back("Women");
    s.push(temp1);
    assert(s.peek() == "Women"); //To prove all items have been pushed to vec
    cout << "top of stack is: " << s.peek() << endl; 
    s.pop();
    s.pop();
    assert(s.peek() == "There are");  //To see if There are still remains to prove that 
    							 //vector temp has been pushed and combined with listed stack
    cout << "top of stack is: " << s.peek() << "\n" << endl; 
    s.pop(); //Clear stack

    s.push("Black");  //Testing push_new to see if it accepts duplicates
    s.push("Black"); //Since there is already "Black", it will not do anything
    s.pop(); 
    s.pop(); //Should make the stack empty
    assert(s.is_empty());

    cout << "\n****Push_new testing with new string\n" << endl;
    s.push("Sauce me the numbers"); 
    s.push("For the anime obviously"); //Not part of stack originally so it will add it
    s.pop(); //Popped the top of stack
    assert(s.peek() == "Sauce me the numbers"); //Black should be remaining 
    s.pop();

    s.push("Hi");
    s.push("Bob");
    s.push("Dhillon");
    assert(!s.is_empty());
    assert(s.peek() == "Dhillon");
    s.pop_all();

    cout << "****Pop testing for vectors rather then just strings (empty vector trial)\n" << endl;

    assert(s.is_empty());
    s.push(temp1);
    assert(s.peek() == "Women");
    cout << "top of stack is: " << s.peek() << endl;
    s.pop();
    cout << "top of stack is: " << s.peek() << endl;
    assert(s.peek() == "Interested");
    s.pop();
    assert(s.is_empty());

    cout << "****Pop testing for vectors rather then just strings (filled vector trial)\n" << endl;
    temp1.push_back("Ice cream");
    temp1.push_back("Cake");
    temp1.push_back("is delicious!");
    s.push(temp1);
    s.pop();
    assert(s.peek() == "Cake");
    cout << "top of stack is: " << s.peek() << endl;
    s.pop();
    cout << "top of stack is: " << s.peek() << endl;
    s.pop();
    cout << "top of stack is: " << s.peek() << endl;
    s.push("Let the rivers flow in you1234"); //integers in strings
    cout << "top of stack is: " << s.peek() << endl;
    assert(s.peek() == "Let the rivers flow in you1234");
    //COME BACK TO THIS

    s.pop();
    s.push(temp1);
    s.pop_all();
    assert(s.is_empty());

    s.push("Breakfast in");
    s.push("Bed");
    s.pop_all();
    assert(s.is_empty());


    // ... put testing for List_stack here ...

    cout << "All List_stack tests passed\n";
} // main
