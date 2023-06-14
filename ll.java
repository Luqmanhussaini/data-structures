
import java.util.*;
 class LinkedList{
    LinkedList next;
    
    int data;
    LinkedList(){}
    LinkedList(int d){
        this.data=d;
    }
    LinkedList(int d, LinkedList node){
        this.data=d;
        this.next=node;
    }
}


public  class Main{
     
public  static LinkedList insertfirst(LinkedList head, int n){
    LinkedList node=new LinkedList(n);
    node.next=head;
    head=node;
    return head;
}
public  static LinkedList insertlast(LinkedList head, int n){
    LinkedList node=new LinkedList(n);
    LinkedList tem=head;
    while(tem.next!=null){
        tem=tem.next;
    }
    tem.next=node;
    
    return head;
}
public  static LinkedList insertpos(LinkedList head, int pos,int n){
    LinkedList node=new LinkedList(n);
    LinkedList tem=head;
    if(head==null)head=node;
    else{
        while(pos-->0){
            tem=tem.next;
        }
        node.next=tem.next;
        tem.next=node;
    }
    return head;
}

	public static void main(String[] args) {
	    Scanner read=new Scanner(System.in);
	    LinkedList head=new LinkedList();
	    LinkedList temp=head;
	    int n=5;
	    while(n-->0){
	        LinkedList x=new LinkedList(read.nextInt());
	        temp.next=x;
	        temp=x;
	    }
	    n=5;
	    System.out.println("insert at first:");
	    int num=read.nextInt();
	    head=head.next;
	    head=insertfirst(head, num);
	    temp=head;
	     while(temp!=null){
	        System.out.print(temp.data+" ");
	        temp=temp.next;
	        
	    }
	    System.out.println();
	    
	    System.out.println("insert at last:");
	    num=read.nextInt();
	    head=insertlast(head, num);
	    temp=head;
	     while(temp!=null){
	        System.out.print(temp.data+" ");
	        temp=temp.next;
	        
	    }
	    System.out.println();
	    int pos=read.nextInt();
	    num=read.nextInt();
	    
	    head=insertpos(head, pos, num);
	    while(head!=null){
	        System.out.print(head.data+" ");
	        head=head.next;
	        
	    }
	    
	}
}

