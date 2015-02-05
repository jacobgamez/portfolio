//Jacob Gamez
//This is a stack implementation for Java

import java.util.ArrayList

class stack {

    //exception handling classes
    //left empty
    class Overflow{};
    class Underflow{};

    //Create arraylist el that will be stack
    private  ArrayList<int> el = new ArrayList<>();
    
    //Constructor has no work bc arraylist handles
    public stack() {/*Nothing to do*/}

    //destructor clears stack using clearIt()
    //leaves behind no cells
    public ~stack() {clearIt();}

    //return true if size is 0, otherwise return false
    public bool isEmpty()
    {
	if (el.size()==0)
	    return true;

	else return false;
    }

    //Adds element to el
    public void push(int elem)
    {
	if (isFull())
	    throw new Overflow();
	else 
	    el.add(elem);
    }
    // Removes elem from el and gives it back
    public void pop(int elem)
    {
	if (isEmpty())
	    throw new Underflow();

	else
	    {
		//put top value from stack into el
		elem = el[el.size()-1];
		el.remove(el.size()-1);
	    }
    }

    public void topElem(int elem)
    {
	if (isEmpty())
	    throw new Underflow();
	else
	    elem = el[el.size()-1];
    }

    public void displayAll()
    {
	if (isEmpty()) System.out.println("[empty]");
	else for (int i=0; i>=el.size(); i++)
		 System.out.println(el[i]);
    }

    public void clearIt()
    {
	int leftover;
	while (!isEmpty())
	    pop(leftover);
    }
}
