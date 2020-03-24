import LinkedList.*;

public class Main {
    public static void main(String[] argv) {
        DoublyLinkedList<Character> l = new DoublyLinkedList<Character>();
        l.append('a');
        l.append('b');
        l.prepend('c');


        DoublyLinkedNode<Character> c = l.getNode(1);
        l.remove(c);

        c = l.getLastNode();
        l.insertBefore(c, 'r');
        l.insertAfter(c.getPrev(), 'a');
        c = l.getHeadNode();

        System.out.println(l.toString());
    }
}
