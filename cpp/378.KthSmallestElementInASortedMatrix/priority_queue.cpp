class Solution {
    struct Node{
        int x,y;
        int val;
    };
    struct compare{
        bool operator()(Node& a, Node& b){
            return a.val>b.val;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row=matrix.size(),col=matrix[0].size();
        vector< vector<int> >visited(row,vector<int>(col,0));
        priority_queue<Node,vector<Node>,compare>qe;
        qe.push( Node{0,0,matrix[0][0]});
        visited[0][0]=1;
        while(--k){
            Node cur=qe.top();
            if(cur.x+1<row&&visited[cur.x+1][cur.y]==0){
                qe.push( Node{cur.x+1,cur.y,matrix[cur.x+1][cur.y]});
                visited[cur.x+1][cur.y]=1;
            }
            if(cur.y+1<col&&visited[cur.x][cur.y+1]==0){
                qe.push( Node{cur.x,cur.y+1,matrix[cur.x][cur.y+1]});
                visited[cur.x][cur.y+1]=1;
            }
            qe.pop();
        }
        return qe.top().val;
    }
};
