class Solution {
public:
    // bool solveRec(int upi, int upj, int righti, int rightj, int downi, int downj, int lefti, int leftj, int i,string word,vector<vector<char>>& board){
    //     if(upi>=0 && upj>=0 && word[i] == board[upi][upj]) return true;
    //     if(righti>=0 && rightj>=0 && word[i] == board[righti][rightj]) return true;
    //     if(downi>=0 && downj>=0 && word[i] == board[downi][downj]) return true;
    //     if(lefti>=0 && leftj>=0 && word[i] == board[lefti][leftj]) return true;
    //     return false;

    // }

    bool search(int i,int j,vector<vector<char>>& board, string& word,int n,int m,int k){
        if(k == word.size()) return true;
        if(i<0 || j<0 || i==n || j==m || board[i][j] != word[k]) return false;
        
        board[i][j] = '#'; // so we don't visit again

        bool up = search(i-1, j, board, word, n, m, k+1);
        bool right = search(i, j+1, board, word, n, m, k+1);
        bool down = search(i+1, j, board, word, n, m, k+1);
        bool left = search(i, j-1, board, word, n, m, k+1);

        board[i][j] = word[k]; // replacing the same char so we don't distord board

        return up || right || down || left;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(search(i,j,board,word,n,m,0)) return true;
                }
            }
        }
        return false;


        // int n = word.size();
        // int loci = -1;
        // int locj = -1;
        // int i;
        // for(i=0; i<board.size(); i++){
        //     for(int j=0; j<board[0].size(); j++){
        //         if(word[0] == board[i][j]){
        //             loci = i;
        //             locj = j;
        //         }
        //     }
        // }
        // if(i == board.size()) return false;

        // for(int i=1; i<word.size(); i++){
        //     int upi = loci-1, upj = locj;
        //     int downi = loci+1, downj = locj;
        //     int lefti = locj-1, leftj = loci;
        //     int righti = locj+1, rightj = loci;
        //     bool check = solveRec(upi,upj,righti,rightj,downi,downj,lefti,leftj,i,word,board);
        //     if(!check) return false;
        // }
        // return true;
    }
};