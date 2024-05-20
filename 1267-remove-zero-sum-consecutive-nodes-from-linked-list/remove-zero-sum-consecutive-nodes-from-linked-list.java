/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        HashMap<Integer, ListNode> prefixSum = new HashMap<>(); 
        int sum = 0; 
        // this represents the starting point
        ListNode dummyNode = new ListNode(0, head); 
        ListNode cur = dummyNode; 
        while (cur != null) {
            sum += cur.val; 
            // if there's zero sum consequtive sequence, this will
            // update with the sequene endpoint, and everyth starts
            // from there
            prefixSum.put(sum, cur); 
            cur = cur.next; 
        }

        cur = dummyNode; 
        sum = 0; 
        while (cur != null) {
            sum += cur.val; 
            ListNode endPoint = prefixSum.get(sum); 
            // updates cur pointer to the endPoint of the sequence if 
            // it exists else endPoint literally points to itself
            cur.next = endPoint.next; 
            cur = cur.next; 
        }
        return dummyNode.next; 
    }
}

/*
How to track and remember the consecutive sums that we have? 
Use a hashmap? [sum] -> node

we calculate the prefix sum, and store [prefixsum] = node
if there is a zero sum
- the endpoint replaces the startpoint in the hashmap
    indicating a skip in the nodes
- Do a final iteration that updates
    cur.next = table[sum].next
    // this links to the endnode shortcut, 
    // if there is no shortcut, table[sum] will just to point itself 
    cur = cur.next
*/ 