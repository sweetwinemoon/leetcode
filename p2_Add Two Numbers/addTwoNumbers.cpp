
#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
/**     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int dig = 0;
        ListNode* lution=new ListNode();
        ListNode* head =lution;
        while(l1!=nullptr || l2!=nullptr){
            if(l1!=nullptr && l2!=nullptr){
                if((sum=l1->val+l2->val+dig)<10){
                    lution->val=sum;
                    dig = 0;
                }else{
                    lution->val=sum%10;
                    dig = 1;
                }
            }else{
                if(dig == 0){
                    if(l1!= nullptr)lution->val=l1->val;
                    else if(l2!=nullptr)lution->val=l2->val;
                }else{
                    if(l1!= nullptr){
                        if((sum = l1->val+dig)<10){
                            lution->val=sum;
                            dig = 0;
                        }else{
                            lution->val=sum%10;
                            dig = 1;
                        }
                    }
                    if(l2!= nullptr){
                        if((sum = l2->val+dig)<10){
                            lution->val=sum;
                            dig = 0;
                        }else{
                            lution->val=sum%10;
                            dig = 1;
                        }
                    }
                }
            }
            if((l1 != nullptr && l1->next != nullptr)||(l2 != nullptr && l2->next != nullptr) || dig == 1)
            {
                lution->next=new ListNode(dig);
                lution=lution->next;
            }
            if(l1 != nullptr && l1->next != nullptr)l1=l1->next;
            else l1 = nullptr;
            if(l2 != nullptr && l2->next != nullptr)l2=l2->next;
            else l2 = nullptr;
        }
        lution=head;
        return lution;
    }
    **/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* lution = head;
        int dig = 0;

        while (l1 || l2 || dig) {
            int sum = dig;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            lution->next = new ListNode(sum % 10);
            lution = lution->next;
            dig = sum / 10;
        }

        return head->next;
}

};

int main(int argc,char* argv[]){
    ListNode* lists1=new ListNode(9,new ListNode(9,new ListNode(9)));
    ListNode* lists2=new ListNode(9,new ListNode(9,new ListNode(9,new ListNode(9,new ListNode(9)))));
    Solution solution;
    ListNode* l = solution.addTwoNumbers(lists1,lists2);
    while(l!=nullptr){
        std::cout<<l->val<<"->";
        l=l->next;
    }
    std::cout<<"nullptr"<<std::endl;
    return 0;
}