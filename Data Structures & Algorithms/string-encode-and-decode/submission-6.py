class Solution:

    def encode(self, strs: List[str]) -> str:
        result=""
        
        for i in strs:
            result+=str(len(i))
            result+='#'
            result+=i
        
        return result
        

    def decode(self, s: str) -> List[str]:
        temp=""
        result=[]
        flag=False
        i=0
        while i<len(s):

            if s[i]>='0' and s[i]<='9':
                temp+=s[i]
                flag=True
            else:
                if flag:
                    length=int(temp)
                    result.append(s[i+1:i+length+1])
                    i=i+length
                    temp=""
                    flag=False
            i=i+1
            
        return result

