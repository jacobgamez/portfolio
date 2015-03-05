//An example of a basic linked list in Java
//A basic sample to demonstrate concept; not a complete program yet

class LL
{
    private Node head;
    private int count;

    //Linked List Constructor
    public LL() 
    {
	head = new Node(null);
	listCount = 0;
    }

    //Appends element to end of list
    public void addEnd(obj data)//arbitrary terms
    {
	Node temp = new Node(data);
	Node curr = head;

	while (curr.getNext() != null)
	    {
		curr = curr.getNext();
	    }

	curr.setNext(temp);
	count++;
    }
}

//etc.
