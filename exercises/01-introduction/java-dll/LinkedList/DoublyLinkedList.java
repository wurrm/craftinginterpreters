package LinkedList;

public class DoublyLinkedList<T> {
    private DoublyLinkedNode<T> head;

    // Java has no unsigned types?
    private int size;

    public DoublyLinkedList() {
        this.head = null;
    }

    @Override
    public String toString() {
        String prettyPrint = this.head.toString();
        DoublyLinkedNode<T> node = head.getNext();

        while (node != null) {
            prettyPrint += "->" + node.toString();
            node = node.getNext();
        }

        return prettyPrint;
    }

    public DoublyLinkedNode<T> getNode(int position) {
        if (this.isEmpty()) {
            // TODO Exceptions
            return null;
        }

        if (position < 0) { position += size; }

        DoublyLinkedNode<T> node = this.head;
        for (int i = 0; i < position; ++i) {
            node = node.getNext();

            if (node == null) {
                // TODO Exceptions
                return null;
            }
        }

        return node;
    }

    public DoublyLinkedNode<T> getHeadNode() {
        return this.head;
    }

    public DoublyLinkedNode<T> getLastNode() {
        DoublyLinkedNode<T> node = this.head;

        if (node == null) {
            return null;
        }

        while (node.getNext() != null) {
            node = node.getNext();
        }

        return node;
    }

    public void prepend(T value) {
        DoublyLinkedNode<T> node = new DoublyLinkedNode<T>(value);
        this.head.setPrev(node);
        node.setNext(this.head);
        this.head = node;
        ++this.size;
    }

    public void append(T value) {
        DoublyLinkedNode<T> last = this.getLastNode();

        if (last == null) {
            this.head = new DoublyLinkedNode<T>(value);
        }
        else {
            DoublyLinkedNode<T> node = new DoublyLinkedNode<T>(value);
            last.setNext(node);
            node.setPrev(last);
        }

        ++this.size;
    }

    private void insertBetween(DoublyLinkedNode<T> left, DoublyLinkedNode<T> right, DoublyLinkedNode<T> middle) {
        if (middle == null || left == null && right == null) {
            // TODO Exception
            return;
        }

        if (left != null) {
            left.setNext(middle);
            middle.setPrev(left);
        }

        if (right != null) {
            middle.setNext(right);
            right.setPrev(middle);
        }

        if (right == this.head) {
            this.head = middle;
        }

        ++this.size;
    }

    public void insertBefore(DoublyLinkedNode<T> node, T value) {
        if (node == null) {
            // TODO Exception
            return;
        }

        this.insertBetween(node.getPrev(), node, new DoublyLinkedNode<T>(value));
    }

    public void insertAfter(DoublyLinkedNode<T> node, T value) {
        if (node == null) {
            // TODO Exception
            return;
        }

        this.insertBetween(node, node.getNext(), new DoublyLinkedNode<T>(value));
    }

    public void remove(DoublyLinkedNode<T> node) {
        if (node == null) {
            // TODO Exception
            return;
        }

        else if (this.size == 1) {
            this.head = null;
        }
        else if (node.getPrev() == null) {
            this.head = node.getNext();
        }
        else if (node.getNext() == null) {
            DoublyLinkedNode<T> n = null;
            node.getPrev().setNext(n);
        }
        else {
            node.getPrev().setNext(node.getNext());
            node.getNext().setPrev(node.getPrev());
        }

        --this.size;
    }

    public int getSize() {
        return this.size;
    }

    public boolean isEmpty() {
        return this.size == 0;
    }
}
