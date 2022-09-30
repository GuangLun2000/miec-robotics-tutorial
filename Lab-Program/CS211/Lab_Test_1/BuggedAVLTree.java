package MIEC_CS211.Lab_Test_1;


public class BuggedAVLTree<K extends Comparable<K>, V> {
	private Node root;

	private class Node {
		private K key;
        private V value;
        Node leftChild, rightChild;
        int height;
        

        public Node(K key, V value) {
        	this.key = key;
            this.value = value;
        }
    }

	private int height(Node node) {
		return node == null ? -1 : node.height;
	}


	private Node rotateWithLeftChild(Node k) {
		Node temp = k.leftChild;
        k.leftChild = temp.rightChild;
        temp.rightChild = k;
        k.height = Math.max(height(k.leftChild), height(k.rightChild)) + 1;
        temp.height = Math.max(height(temp.leftChild), k.height) + 1;

        return temp;
	}


	private Node rotateWithRightChild(Node k) {
		Node temp = k.rightChild;
        k.rightChild = temp.leftChild;
        temp.leftChild = k;
        k.height = Math.max(height(k.leftChild), height(k.rightChild)) + 1;
        temp.height = Math.max(height(temp.rightChild), k.height) + 1;

        return temp;
    }

	private Node doubleWithLeftChildRightSubtree(Node k) {
		k.leftChild = rotateWithRightChild(k.leftChild);
        return rotateWithLeftChild(k);
    }

	private Node doubleWithRightChildLeftSubtree(Node k) {
		k.rightChild = rotateWithLeftChild(k.rightChild);
        return rotateWithRightChild(k);
    }

	
	
	
	
	
	private Node balance(Node node) {
		if (node == null)
			return node;
	
	    if(height(node.leftChild) - height(node.rightChild) > 1) {
	    	if (height(node.leftChild.leftChild) >= height(node.leftChild.rightChild)) {
	    			node = rotateWithLeftChild(node);
	            } else {
	            	node = doubleWithLeftChildRightSubtree(node);
	            }
	    } else if (height(node.rightChild) - height(node.leftChild) > 1) {
	    	if (height(node.rightChild.rightChild) >= height(node.rightChild.leftChild)) {
	    			node = rotateWithRightChild(node);
	            } else {
	            	node = doubleWithRightChildLeftSubtree(node);
	            }
		}
	    
	    node.height = Math.min(height(node.rightChild), height(node.leftChild)) + 1;
	    return node;
	}
	
	
	
	
	

	public void insert(K key, V value) {
		root = insert(key, value, root);
    }

	private Node insert(K key, V value, Node currentRoot) {
		if (currentRoot == null)
			return new Node(key, value);

        if (key.compareTo(currentRoot.key) < 0) {
        	currentRoot.leftChild = insert(key, value, currentRoot.leftChild);
        } else if (key.compareTo(currentRoot.key) > 0) {
        	currentRoot.rightChild = insert(key, value, currentRoot.rightChild);
        }

        return balance(currentRoot);
    }

	
	
	
	
	
	public void remove(K key) {
		root = remove(key, root);
    	}

	private Node remove(K toBeRemoved, Node currentRoot) {
		if (currentRoot == null)
			return currentRoot;

        if (toBeRemoved.compareTo(currentRoot.key) < 0) {
        	currentRoot.leftChild = remove(toBeRemoved, currentRoot.leftChild);
        } else if (toBeRemoved.compareTo(currentRoot.key) > 0) {
        	currentRoot.rightChild = remove(toBeRemoved, currentRoot.rightChild);
        } else if (currentRoot.leftChild != null && currentRoot.rightChild != null) {
        	currentRoot.key = findMin(currentRoot.rightChild).key;
            currentRoot.rightChild = remove(currentRoot.key, currentRoot.rightChild);
        } else {
        	currentRoot = (currentRoot.leftChild != null) ? currentRoot.leftChild : currentRoot.rightChild;
        }

        return balance(currentRoot);
    }

	
	
	
	private Node findMin(Node currentRoot) {
		//first
		if (currentRoot == null)
			return currentRoot;

        while (currentRoot.leftChild != null)
        	currentRoot = currentRoot.leftChild;

        //second
        return currentRoot;
    }

	
	
	
	
	
	public void inOrderWalkRecursive() {
		inOrderWalkRecursive(root);
    }

	private void inOrderWalkRecursive(Node currentRoot) {
		if(currentRoot ==null){
			return;
		} else {
			inOrderWalkRecursive(currentRoot.leftChild);
	    	System.out.print(currentRoot.key + " ");
	    	inOrderWalkRecursive(currentRoot.rightChild);
		}
    }

	/*
	 * I have realized the corrert output
	 * But I can not find the 5th error
	 * I have tried my best.
	 * by Hanlin Cai 832002117
	 */
	
	public static void main(String[] args) {
		BuggedAVLTree<Integer, String> avl = new BuggedAVLTree<>();
        int[] tree = { 16, 8, 24, 4, 12, 20, 28, 2, 6, 10, 14, 26, 1 };
        
        for (int k : tree)
       	avl.insert(k, "empty");
       	avl.inOrderWalkRecursive();
        avl.remove(24);
        System.out.println();
        avl.inOrderWalkRecursive();

    }

}
