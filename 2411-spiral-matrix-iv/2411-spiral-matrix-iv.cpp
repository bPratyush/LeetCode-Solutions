/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int i=0,j=0,turn=0;
        vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> res(m,vector<int>(n,-1));
        while(head){
            res[i][j]=head->val;
            int newi=i+dir[turn].first,newj=j+dir[turn].second;
            if(min(newi,newj)<0||newi>=m||newj>=n||res[newi][newj]!=-1){
                turn=(turn+1)%4;
            }
            i+=dir[turn].first;
            j+=dir[turn].second;
            head=head->next;
        }
        return res;
    }
};