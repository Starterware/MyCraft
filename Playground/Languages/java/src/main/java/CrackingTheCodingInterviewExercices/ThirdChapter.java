package CrackingTheCodingInterviewExercices;

import java.util.*;

public class ThirdChapter {
    static public class MultiStack {
        Integer[] values;
        int nbrOfStacks;
        int arraySize;
        int[] pos;
        int[] startPos;

        public MultiStack(int nbrOfStacks, int arraySize) {
            values = new Integer[arraySize];
            this.nbrOfStacks = nbrOfStacks;
            this.arraySize = arraySize;
            pos = new int[nbrOfStacks];
            startPos = new int[nbrOfStacks+1];
            for (int i = 0; i < nbrOfStacks; i++) {
                pos[i] = i * arraySize / nbrOfStacks;
                startPos[i] = pos[i];
            }
            startPos[nbrOfStacks] = arraySize;
        }

        public Integer pop(int stack) {
            if (stack < 0 || stack >= nbrOfStacks || pos[stack] == startPos[stack]) return null;
            pos[stack]--;
            return values[pos[stack]];
        }

        public Integer top(int stack) {
            if (stack < 0 || stack >= nbrOfStacks || pos[stack] == startPos[stack]) return null;
            return values[pos[stack] - 1];
        }

        public boolean isEmpty(int stack) {
            if (stack < 0 || stack >= nbrOfStacks || pos[stack] == startPos[stack]) return true;
            return pos[stack] == startPos[stack];
        }

        public boolean push(int stack, Integer value) {
            if (stack < 0 || stack > nbrOfStacks || pos[stack] >= startPos[stack+1]) return false;
            values[pos[stack]] = value;
            pos[stack]++;
            return true;
        }
    }

    static public class StackWithMin extends Stack<Integer> {
        Stack<Integer> minimums = new Stack<>();

        @Override
        public Integer push(Integer item) {
            if (item <= min())
                minimums.push(item);
            return super.push(item);
        }

        @Override
        public synchronized Integer pop() {
            Integer item = super.pop();
            if (item.equals(min()))
                minimums.pop();
            return item;
        }

        public Integer min() {
            if (minimums.isEmpty()) return Integer.MAX_VALUE;
            return minimums.peek();
        }
    }

    static public class SetOfStacks {
        static final int STACK_SIZE = 2;
        List<Stack<Integer>> stacks = new ArrayList<>();
        int cur = -1;

        public Integer push(Integer item) {
            if (cur == -1 || stacks.get(cur).size() == STACK_SIZE) {
                cur++;
                stacks.add(new Stack<>());
            }
            return stacks.get(cur).push(item);
        }

        public Integer pop() {
            if (cur == -1) return null;
            Integer item = stacks.get(cur).pop();
            while (cur >= 0 && stacks.get(cur).size() == 0)
                cur--;
            return item;
        }

        public Integer pop(int stack) {
            if (stack < 0 || stack > cur || stacks.get(stack).isEmpty()) return null;
            if (stack == cur) return pop();
            return stacks.get(stack).pop();
        }

        public Integer peek() {
            if (cur == -1) return null;
            return stacks.get(cur).peek();
        }

        public boolean isEmpty() {
            return cur == -1;
        }
    }

    public void hanoi(int n, Stack<Integer> source, Stack<Integer> destination, Stack<Integer> buffer) {
        if (n == 0) return;
        if (n == 1) {
            destination.push(source.pop());
            return;
        }
        hanoi(n-1, source, buffer, destination);
        destination.push(source.pop());
        hanoi(n-1, buffer, destination, source);
    }

    public static class MyQueue<T> {
        Stack<T> oldStack = new Stack<>();
        Stack<T> newStack = new Stack<>();

        public int size() {
            return oldStack.size() + newStack.size();
        }

        public boolean isEmpty() {
            return size() == 0;
        }

        public void add(T item) {
            newStack.push(item);
        }

        public T peek() {
            if (isEmpty())
                return null;
            shiftStacks();
            return oldStack.peek();
        }

        public T remove() {
            if (isEmpty())
                return null;
            shiftStacks();
            return oldStack.pop();
        }

        private void shiftStacks() {
            if (oldStack.isEmpty()) {
               while (!newStack.isEmpty()) {
                   oldStack.push(newStack.pop());
               }
            }
        }
    }

    public void sort(Stack<Integer> s) {
        Stack<Integer> tmp = new Stack<>();
        while (!s.isEmpty()) {
            Integer value = s.pop();
            while (!tmp.isEmpty() && tmp.peek() < value)
                s.push(tmp.pop());
            tmp.push(value);
        }
        while (!tmp.isEmpty())
            s.push(tmp.pop());
    }

    public static class Animals {
        private Deque<Dog> dogs = new ArrayDeque<>();
        private Deque<Cat> cats = new ArrayDeque<>();
        private int order = 0;

        public static class Animal {
            String name;
            int order;

            public Animal(String name) {
                this.name = name;
            }

            public int getOrder() {
                return order;
            }

            public void setOrder(int order) {
                this.order = order;
            }

            public boolean isOlderThan(Animal other) {
                return order < other.order;
            }
        }

        public static class Cat extends Animal {
            public Cat(String name) {
                super(name);
            }
        }

        public static class Dog extends Animal {
            public Dog(String name) {
                super(name);
            }
        }

        public void enqueue(Cat c) {
            enqueueAnimal(c);
            cats.add(c);
        }

        public void enqueue(Dog d) {
            enqueueAnimal(d);
            dogs.add(d);
        }

        private void enqueueAnimal(Animal a) {
            a.setOrder(order);
            order++;
        }

        public Animal dequeue() {
            if (cats.size() > 0 && (dogs.size() == 0 || cats.peek().isOlderThan(dogs.peek()))) {
                return cats.poll();
            } else if (dogs.size() > 0){
                return dogs.poll();
            }
            return null;
        }

        public Cat dequeueCat() {
            if (cats.size() == 0) return null;
            return cats.poll();
        }

        public Dog dequeueDog() {
            if (dogs.size() == 0) return null;
            return dogs.poll();
        }
    }
}
