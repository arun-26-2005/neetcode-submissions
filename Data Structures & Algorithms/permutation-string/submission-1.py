class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if(len(s1)>len(s2)):
            return False
        l1=[0 for _ in range(26)]
        l2=[0 for _ in range(26)]
        for i in range(len(s1)):
            l1[ord(s1[i])-ord('a')]+=1
            l2[ord(s2[i])-ord('a')]+=1
        count=0
        for i in range(len(l1)):
            if l1[i]==l2[i]:
                count+=l1[i]
        if count==len(s1):
            return True
        elif len(s1)==len(s2):
            return False
        l2[ord(s2[0])-ord('a')]-=1
        low=1
        high=len(s1)
        while(high<len(s2)):
            count=0
            l2[ord(s2[high])-ord('a')]+=1
            for i in range(len(l1)):
                if l1[i]==l2[i]:
                    count+=l1[i]
            if count==len(s1):
                return True
            else:
                l2[ord(s2[low])-ord('a')]-=1
                low+=1;
                high+=1;
        return False


