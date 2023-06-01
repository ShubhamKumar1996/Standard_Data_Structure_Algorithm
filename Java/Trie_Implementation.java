import java.util.*;
public class Main
{
    public static class Node {
        public char ch;
        public Node[] children;
        public boolean isEnd;
        public Node(char ch) {
            this.ch = ch;
            children = new Node[26];
            for(int i=0;i<26;i++) {
                this.children[i] = null;
            }
            this.isEnd = false;
        }
    }
    public static void insert(Node root, String str) {
        Node currRoot = root;
        for(int i=0;i<str.length();i++) {
            char ch = str.charAt(i);
            int index = (int)(ch - 'a');
            if(currRoot.children[index] == null) {
                Node newNode = new Node(ch);
                currRoot.children[index] = newNode;
            }
            currRoot = currRoot.children[index];
        }
        currRoot.isEnd = true;
    }
    public static boolean search(Node root, String str) {
        Node currRoot = root;
        for(int i=0;i<str.length();i++) {
            char ch = str.charAt(i);
            int index = (int)(ch - 'a');
            if(currRoot.children[index] == null) {
                return false;
            }
            currRoot = currRoot.children[index];
        }
        return currRoot.isEnd;
    }
	public static void main(String[] args) {
	    Node root = new Node('.');
	    System.out.print("Word Count for Insertion: ");
	    Scanner scanner = new Scanner(System.in);
	    int n = scanner.nextInt();
	    System.out.println("List of words:-");
	    for(int i=0;i<n;i++) {
	        String str = scanner.next();
	        insert(root, str);
	    }
	   while(true) {
	   System.out.printf("\n1.Search Word\n2.Exit\n");
	   System.out.print("Enter Choice: ");
    	   int choice = scanner.nextInt();
    	   switch(choice) {
    	       case 1:
    	           System.out.print("Enter search word: ");
    	           String str = scanner.next();
    	           if(search(root, str)) {
    	               System.out.println("Found");
    	           } else {
    	               System.out.println("Not Found");
    	           }
    	           break;
    	       default:
    	            System.exit(0);
    	   }
	   }
	}
}
