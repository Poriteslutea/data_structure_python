import java.util.*;
public class Main{

    //主函式
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5,6,7};
        var root = buildTree(arr,0, arr.length - 1);
    }



    // 建立平衡二元樹
    public static Node buildTree(int[] arr, int li, int hi) {
        if (li>hi) return null; //越界代償
        var mi = li + (hi - li) / 2;
        var leftSubtreeRoot = buildTree(arr, li, mi - 1);
        var rightSubtreeRoot = buildTree(arr, mi + 1, hi);
        var root = new Node(arr[mi]);
        root.left = leftSubtreeRoot;
        root.right = rightSubtreeRoot;
        return root;
    }

}





    

