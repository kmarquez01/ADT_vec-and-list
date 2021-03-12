// adt_vec.cpp

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
// don't #include anything else!

using namespace std;

class Vec_stack : public Stack
{
private:
    vector<string> vec;
public:
    // default constructor makes an empty stack
    Vec_stack() { }

    // Pre-condition:
    //    none
    // Post-condition:
    //    returns true if the stack is empty, and false otherwise
    bool is_empty() const
    { 
        return vec.size() == 0; 
    }

    // Pre-condition:
    //    none
    // Post-condition:
    //    returns the number of elements in this stack
    int size() const
    {
    	return vec.size();
    }

    // Pre-condition:
    //    none
    // Post-condition:
    //    puts x on the top of the stack
    void push(const string& x) 
    {
        vec.push_back(x);
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
    		vec.push_back(v[index]);
    	}
  
    }

    // Pre-condition:
    //    none
    // Post-condition:
    //    if s occurs anywhere on the stack, then does nothing; otherwise,
    //    pushes s onto the stack
    void push_new(const string& s)
    {
    	int index = 0;

    	for(index = 0; index < vec.size(); index++)
    	{
    		if(s == vec[index])
    		{
    			cout << "It already exists" << endl; //Just wrote this to confirm it worked
    		}
    		else
    		{
    			vec.push_back(s);
    		}
    	}
    	
    }

    // Pre-condition:
    //    !is_empty()
    // Post-condition: 
    //   removes and returns the top element of the stack
    string pop() 
    {
        string result = vec.back();
        vec.pop_back();
        return result;
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
    //   returns a copy of the top element of the stack (without removing it)
    string peek() const 
    {
        return vec.back();
    }
}; // class Vec_stack


int main() 
{
    // ... put testing for Vec_stack here ...
    Vec_stack s;
    
    vector<string> temp;
    assert(s.is_empty());

    s.push("Welcome to");
    s.push("Narnia");
    assert(!s.is_empty());
    assert(s.peek() == "Narnia");
    s.size();
    cout << "Size is: " << s.size() << endl; //To check if size function works
    assert(s.size() == 2);
    
    string top = s.pop();
    assert(top == "Narnia"); //Narnia popped
    s.pop(); //Welcome to popped
    assert(s.is_empty());

    s.push("Black");
    s.push("Desert");
    s.push("Online");
    s.push("Cool");
    s.pop();
    s.pop();
    assert(!s.is_empty());
    assert(s.peek() == "Desert");

    s.pop();
    assert(!s.is_empty());
    assert(s.peek() == "Black");

    s.pop();
    assert(s.is_empty());

    cout << "****Push_new testing with duplicate\n" << endl;
    s.push("Black");  //Testing push_new to see if it accepts duplicates
    s.push_new("Black"); //Since there is already "Black", it will not do anything
    s.pop(); //Should make the stack empty
    assert(s.is_empty());

    cout << "\n****Push_new testing with new string\n" << endl;
    s.push("Black"); 
    s.push_new("Fire Noodles"); //Not part of stack originally so it will add it
    cout << "top of stack is: " << s.peek() << endl; 
    s.pop(); //Popped the top of stack
    cout << "top of stack is: " << s.peek() << endl; 
    assert(s.peek() == "Black"); //Black should be remaining

    cout << "\n****Push testing with vector as parameter\n" << endl;
    //Testing push function of vectors
    temp.push_back("Cool kids");
    temp.push_back("Nice boys");
    temp.push_back("Saucy behaviour");
    s.push(temp);
    assert(s.peek() == "Saucy behaviour"); //To prove all items have been pushed to vec
    cout << "top of stack is: " << s.peek() << endl; 
    s.pop();
    s.pop();
    s.pop(); 
    assert(s.peek() == "Black");  //To see if Black still remains to prove that 
    							 //vector temp has been pushed and combined with vector vec
    cout << "top of stack is: " << s.peek() << "\n" << endl; 
    s.pop(); //Clear stack

    //Testing pop function with vectors rather then just strings
    cout << "****Pop testing for vectors rather then just strings (empty vector trial)\n" << endl;

    assert(s.is_empty());
    s.push(temp);
    assert(s.peek() == "Saucy behaviour");
    s.pop();
    assert(s.peek() == "Nice boys");


    cout << "****Pop testing for vectors rather then just strings (filled vector trial)\n" << endl;
    temp.push_back("Ice cream");
    temp.push_back("Cake");
    temp.push_back("is delicious!");
    s.push(temp);
    s.pop();
    assert(s.peek() == "Cake");
    //COME BACK TO THIS

    s.push("Oregairu is 1234"); //Testing with numbers in strings
    s.push("Great ----"); //Testing with special characters in strings
    s.pop_all(); //Testing pop_all function which gets rid of everything in stack
    assert(s.is_empty());

    s.push("Together we will prosper");
    s.push("But only if we ate fire noodles at 4am");
    s.pop();
    assert(s.peek() == "Together we will prosper");
    s.pop_all();
    assert(s.is_empty());

    cout << "All Vec_stack tests passed\n";
} // main

//For question 3
//i added an extra method to stack and used that to implement 
//the operator without any changes to parameters

//List_stack test_stack;