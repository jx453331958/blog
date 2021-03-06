/**
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function (l1, l2) {
  const newList = {
    val: -1,
    next: null,
  };

  let tempList = newList;

  while (l1 && l2) {
    if (l1.val < l2.val) {
      tempList.next = l1;
      l1 = l1.next;
    } else {
      tempList.next = l2;
      l2 = l2.next;
    }

    tempList = tempList.next;
  }

  tempList.next = l1 || l2;

  return newList.next;
};

var mergeTwoLists2 = function(l1, l2) {
  const newList = {
      val: -1,
      next: null
  }

  const recursion = (list, l1, l2) => {
      if (!l1 && !l2) return;
      if (!l1 || !l2) {
          list.next = l1 || l2;
          return;
      }

      let temp = list;
      if (l1.val < l2.val) {
          temp.next = l1;
          l1 = l1.next;
      }  else {
          temp.next = l2;
          l2 = l2.next;
      }
      temp = temp.next;
      recursion(temp, l1, l2);
  }

  recursion(newList, l1, l2);
  return newList.next;
};
