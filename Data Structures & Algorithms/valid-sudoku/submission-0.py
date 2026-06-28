class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        l1=[]
        l2=[]
        for i in range(len(board)):  
            for j in range(len(board)):
                if board[i][j]!='.' and board[i][j] not in l1:
                    l1.append(board[i][j])
                elif board[i][j]!='.':
                    return False
                if board[j][i]!='.' and board[j][i] not in l2:
                    l2.append(board[j][i])
                elif board[j][i]!='.':
                    return False
                
            l1=[]
            l2=[]
        i=0
        while i<len(board):
            l=[]
            for j in range(i,i+3):
                for k in range(0,3):
                    if board[j][k]!='.' and board[j][k] not in l:
                        l.append(board[j][k])
                    elif board[j][k]!='.':
                        return False
            l=[]
            for j in range(i,i+3):
                for k in range(3,6):
                    if board[j][k]!='.' and board[j][k] not in l:
                        l.append(board[j][k])
                    elif board[j][k]!='.':
                        return False
            l=[]
            for j in range(i,i+3):
                for k in range(6,9):
                    if board[j][k]!='.' and board[j][k] not in l:
                        l.append(board[j][k])
                    elif board[j][k]!='.':
                        return False

                
            i=i+3
        return True


        

        