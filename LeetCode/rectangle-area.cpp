class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int height = calcOverlap(B, D, F, H);
        int width = calcOverlap(A, C, E, G);
        
        int overlappedArea = height * width;
        
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        
        return area1 + area2 - overlappedArea;
    }

private:
    int calcOverlap(int start1, int end1, int start2, int end2) {
        if (end1 <= start2 || end2 <= start1)
            return 0;
        
        if (start1 >= start2 && end1 <= end2) //line1 is included in line2
            return end1 - start1;
        else if (start2 >= start1 && end2 <= end1) //line2 is included in line1
            return end2 - start2;
        else if (end1 > start2 && end1 <= end2)
            return end1 - start2;
        else
            return end2 - start1;
    }
};
