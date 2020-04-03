#include "stdio.h"
#include "stdlib.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* y) : val(x), next(y) {}
};

void appendNext(ListNode **list_point, ListNode **list_1_point, ListNode **list_2_point){
    ListNode *templ1 = *list_1_point;
    ListNode *templ2 = *list_2_point;
    ListNode *temp_res = *list_point;
    if(templ1->next != NULL || templ2->next != NULL){
        if(templ1->next == NULL){
            ListNode *temp_next = new ListNode(0, NULL);
            templ1->next = temp_next;
        }
        if(templ2->next == NULL){
            ListNode *temp_next = new ListNode(0, NULL);
            templ2->next = temp_next;
        }
        *list_1_point = templ1->next;
        *list_2_point = templ2->next;
        ListNode *next = new ListNode(-1, NULL);
        temp_res->next = next;
        *list_point = temp_res->next;
    }
    return;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    /*
        given 2 list and do the addition process
        e.g: 
            list1:5->2->3
            list2:3->8->1
            result:9->0->4
            because 5+3 + 1(carry) -> 8+2 (v:0, carry:1) -> 3+1 
    */
    ListNode* result = new ListNode(-1, NULL);
    int size_of_list_1 = 0;
    int size_of_list_2 = 0;
    ListNode* temp_list1 = l1;
    ListNode* temp_list2 = l2;

    // caclculate the number of the list
    while(true){
        if(temp_list1->next != NULL){
            temp_list1 = temp_list1->next;
            size_of_list_1++;
        }
        if(temp_list2->next != NULL){
            temp_list2 = temp_list2->next;
            size_of_list_2++;
        }
        if(temp_list1->next == NULL && temp_list2->next == NULL){
            break;
        }
    }
    int max_size = size_of_list_1 < size_of_list_2 ? size_of_list_2 : size_of_list_1;

    // deal with the value
    int carry = 0;
    ListNode *list_point = result;
    ListNode *list_1_point = l1;
    ListNode *list_2_point = l2;
    for(int i = 0 ; i <= max_size ; i++){
        if(list_1_point->val > -1 && list_2_point->val > -1){

            printf("%d + %d", list_1_point->val, list_2_point->val);

            int temp_val = list_1_point->val + list_2_point->val;
            if(carry != 0){
                printf(" + carry:%d", carry);
                temp_val += carry;
                carry = 0;
            }
            if(temp_val > 9) {
                temp_val = 10 - temp_val;
                carry++;
                printf(", carry: %d", carry);
            }
            list_point->val = temp_val;
            appendNext(&list_point, &list_1_point, &list_2_point);
            printf("\n");
        }else{
            if(list_1_point->val > -1){
                list_point->val = list_1_point->val;
            }else{
                list_point->val = list_2_point->val;
            }
            list_point->val += carry;
            carry = 0;
            appendNext(&list_point, &list_1_point, &list_2_point);
        }
    }
    list_point = NULL;
    return result;
}

int main(){
    // 9->3->2->0
    ListNode* list_1_4 = new ListNode(9, NULL);
    ListNode* list_1_3 = new ListNode(3, list_1_4);
    ListNode* list_1_2 = new ListNode(2, list_1_3);
    ListNode* list_1_1 = new ListNode(0, list_1_2);

    // 0->1->8->2
    ListNode* list_2_3 = new ListNode(1, NULL);
    ListNode* list_2_2 = new ListNode(8, list_2_3);
    ListNode* list_2_1 = new ListNode(2, list_2_2);

    ListNode* result = addTwoNumbers(list_1_1, list_2_1);
    ListNode* display = result;

    while(true){
        printf("%d", display->val);
        if(display->next == NULL){
            printf("\n");
            break;
        }
        display = display->next;
        printf("<-");
    }
    return 0;
}


