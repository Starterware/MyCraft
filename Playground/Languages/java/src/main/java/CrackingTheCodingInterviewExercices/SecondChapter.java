package CrackingTheCodingInterviewExercices;

import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Stack;

public class SecondChapter {
    public void removeDuplicate(MyList l) {
        if (l.getHead() == null) return;
        MyList.Node n = l.getHead();
        Set<Integer> s = new HashSet<>();
        s.add(n.data);
        while (n.next != null) {
            if (s.contains(n.next.data)) {
                n.next = n.next.next;
            } else {
                s.add(n.next.data);
                n = n.next;
            }
        }
    }

    public void removeDuplicateWithoutBuffer(MyList l) {
        MyList.Node n = l.getHead();
        while (n != null) {
            MyList.Node r = n;
            while (r.next != null) {
               if (r.next.data == n.data) {
                   r.next = r.next.next;
               } else {
                   r = r.next;
               }
            }
            n = n.next;
        }
    }

    public MyList.Node kLast(MyList l, int k) {
        MyList.Node last = l.getHead();
        MyList.Node kLast = l.getHead();
        for (int i = 0; i < k; i++) {
            if (last == null) return null;
            last = last.next;
        }
        while (last != null) {
            last = last.next;
            kLast = kLast.next;
        }
        return kLast;
    }

    public boolean deleteNode(MyList.Node n) {
        if (n == null || n.next == null) return false;
        n.data = n.next.data;
        n.next = n.next.next;
        return true;
    }

    public void partition(MyList l, int x) {
        if (l.getHead() == null) return;
        MyList.Node smaller = new MyList.Node(-1);
        MyList.Node smallerHead = smaller;
        MyList.Node greater = new MyList.Node(-1);
        MyList.Node greaterHead = greater;
        for (MyList.Node n = l.getHead(); n != null; n = n.next) {
            if (n.data < x) {
                smaller.next = n;
                smaller = n;
            } else {
                greater.next = n;
                greater = n;
            }
        }
        smaller.next = greaterHead.next;
        greater.next = null;
        l.getHead().data = smallerHead.next.data;
        l.getHead().next = smallerHead.next.next;
    }

    public MyList addition(MyList a, MyList b) {
        MyList.Node total = new MyList.Node(-1);
        addition(a.getHead(), b.getHead(), total);
        return new MyList(total.next);
    }

    private void addition(MyList.Node a, MyList.Node b, MyList.Node total) {
        int carry = 0;
        while (a != null || b != null) {
            int tmp = carry;
            if (a != null) {
                tmp += a.data;
                a = a.next;
            }
            if (b != null) {
                tmp += b.data;
                b = b.next;
            }
            total.next = new MyList.Node(tmp % 10);
            total = total.next;
            carry = tmp / 10;
        }
        if (carry != 0) {
            total.next = new MyList.Node(carry);
        }
    }

    public MyList additionReverse(MyList a, MyList b) {
        MyList.Node headA = a.getHead();
        MyList.Node headB = b.getHead();
        int lA = length(headA);
        int lB = length(headB);
        if (lA < lB)
            headA = addZeros(headA, lB-lA);
        else
            headB = addZeros(headB, lA-lB);
        MyList.Node total = additionReverse(headA, headB);
        if (total != null && total.data > 10) {
            total = new MyList.Node(total.data/10, total);
            total.next.data %= 10;
        }
        return new MyList(total);
    }

    private MyList.Node addZeros(MyList.Node n, int size) {
        for (int i = 0; i < size; i++) {
            n = new MyList.Node(0, n);
        }
        return n;
    }

    private int length(MyList.Node n) {
        int count = 0;
        while (n != null) {
            count++;
            n = n.next;
        }
        return count;
    }

    private MyList.Node additionReverse(MyList.Node a, MyList.Node b) {
        if (a == null && b == null) return null;
        MyList.Node total = additionReverse(a != null ? a.next : null, b != null ? b.next : null);
        int tmp = 0;
        if (a != null)
            tmp += a.data;
        if (b != null)
            tmp += b.data;
        if (total != null) {
            tmp += total.data / 10;
            total.data %= 10;
        }
        return new MyList.Node(tmp, total);
    }

    public MyList.Node findLoopStart(MyList myList) {
        MyList.Node slow = myList.getHead();
        MyList.Node fast = myList.getHead();
        do {
            if (fast.next == null || fast.next.next == null) return null;
            slow = slow.next;
            fast = fast.next.next;
        } while (slow.data != fast.data);
        slow = myList.getHead();
        while (slow.data != fast.data) {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }

    public boolean isPalindrome(MyList l) {
        MyList.Node slow = l.getHead();
        MyList.Node fast = l.getHead();
        Stack<Integer> stack = new Stack<>();
        while (fast != null && fast.next != null) {
            stack.push(slow.data);
            slow = slow.next;
            fast = fast.next.next;
        }
        if (fast != null)
            slow = slow.next;
        while (!stack.empty()) {
            if (stack.pop() != slow.data)
                return false;
            slow = slow.next;
        }
        return true;
    }

    public static class MyList {
        public MyList() {
        }

        public MyList(List<Integer> dataList) {
            append(dataList);
        }

        public MyList(Node n) {
            this.head = n;
        }

        public static class Node {
            public Node(int data) {
                this.data = data;
            }

            public Node(int data, Node next) {
                this.data = data;
                this.next = next;
            }

            public int data;
            public Node next = null;
        }

        private Node head = null;

        public Node append(int d) {
            Node n = head;
            Node newNode = new Node(d);
            if (n == null) {
                head = newNode;
            } else {
                while (n.next != null) n = n.next;
                n.next = newNode;
            }
            return newNode;
        }

        private void append(List<Integer> dataList) {
            if (dataList.size() > 0) {
                Node n = append(dataList.get(0));
                for (int i = 1; i
                        < dataList.size(); i++) {
                    n.next = new Node(dataList.get(i));
                    n = n.next;
                }
            }
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof MyList)) return false;
            Node a = this.head;
            Node b = ((MyList) o).head;
            if (a == null || b == null)
                return a == b;
            while (a.next != null && b.next != null) {
                if (a.data != b.data) return false;
                a = a.next;
                b = b.next;
            }
            return a.next == b.next;
        }

        @Override
        public int hashCode() {
            return 0; // Not needed
        }

        public Node getHead() {
            return head;
        }
    }
}
