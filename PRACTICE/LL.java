class LL {
   public class Node { 
       int data;
       Node next;

       Node(int data) {
           this.data = data;
           this.next = null;
       }
   }
    
   public Node head = null; 

   public void addFirst(int data){
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }

        newNode.next = head;
        head = newNode;
   }

   public void addLast(int data){
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }

        Node p = head;
        
        while (p.next != null) {
            p = p.next;
        }

        p.next = newNode;
   }

   void addIndex(int index, int data){
        Node newNode = new Node(data);
        if (index == 0) {
            return;
        }
        Node p = head;
        for (int i = 0; i < index - 1 && p != null; i++) {
            p = p.next;
        }
        
        if (p == null) {
            System.out.println("Index out of bounds\n");
            return;
        }

        newNode.next = p.next;
        p.next = newNode;
   }

   int removeFirst(){
        int val = head.data;
        head = head.next;
        return val; 
   }
    
   void removeLast(int data){
        if (head == null) {
        System.out.println("Linked List is empty");
        return;
        }

        Node temp = head;
        Node pre = null;

        if (head.data == data) {
            head = temp.next;
            return;
        }

        while (temp != null && temp.data != data) {
            pre = temp;
            temp = temp.next;
        }

        if (temp == null) {
            return;
        }

        pre.next = temp.next;
   }

    void printList() {
        if (head == null) {
            System.out.println("list is empty");
            return;
        }
        Node p = head;
        while (p != null) {
            System.out.print(p.data + " ");
            p = p.next;
        }
        System.out.println("\n");
    }

    public static void main(String[] args) {
        LL list = new LL();
        list.addFirst(1);
        list.printList();

        list.addLast(5);
        list.printList();

        list.addIndex(1, 7);
        list.printList();

        list.addLast(7);
        list.printList();

        list.addFirst(0);
        list.printList();

        list.removeFirst();
        list.printList();

        list.removeLast(7);
        list.printList();

    }
}