package LinkedList;

public class DoublyLinkedNode<T> {
    private DoublyLinkedNode<T> prev;
    private DoublyLinkedNode<T> next;
    private T value;

    public DoublyLinkedNode(T value) {
        this.prev = null;
        this.next = null;
        this.value = value;
    }

    @Override
    public String toString() {
        return this.value.toString();
    }

    // "Is this the power of java accessors and mutators?"
    // I much prefer the C++ and C# ways of doing this.
    // I'm probably doing something wrong, right?
    public DoublyLinkedNode<T> getPrev() {
        return this.prev;
    }

    public void setPrev(T value) {
        setPrev(new DoublyLinkedNode<T>(value));
    }

    public void setPrev(DoublyLinkedNode<T> node) {
        this.prev = node;
    }

    public DoublyLinkedNode<T> getNext() {
        return this.next;
    }

    public void setNext(T value) {
        setNext(new DoublyLinkedNode<T>(value));
    }

    public void setNext(DoublyLinkedNode<T> node) {
        this.next = node;
    }
}
