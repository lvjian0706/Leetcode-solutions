//方法1
class Solution {
public:
    
    /*
    在第一列中查找目标值应该属于哪一行：在一维数组中查找目标值，有则返回索引，没有返回小于且最接近目标值的索引；
    1. 如果vec[mid]==target， 返回mid；
    2. 如果vec[mid]<target：
    2.1 如果vec[mid+1]<=target，在mid右边继续查找；
    2.2 如果vec[mid+1]>target，返回mid；
    2.3 如果mid==vec.size()-1，说明在右边界，返回vec.size()-1；
    3. 如果vec[mid]>target：
    2.1 如果vec[mid-1]<target，返回mid-1；
    2.2 如果vec[mid-1]>=target，在mid左边继续查找；
    3.3 如果mid==0，说明在左边界，返回0；
    */
    int searchCol(vector<int> vec, int target){
        int left = 0, right = vec.size()-1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(vec[mid]==target) return mid;
            else if(vec[mid]<target){
                if(mid==vec.size()-1) return mid;
                else if(vec[mid+1]<=target) left = mid + 1;
                else return mid;
            }
            else if(vec[mid]>target){
                if(mid==0) return mid;
                else if(vec[mid-1]>=target) right = mid - 1;
                else return mid-1;
            }
        }
        return -1;
    }

    /*
    在对应行中查找目标值：在一维数组中查找目标值，有则返回索引，没有返回-1；
    */
    int searchTarget(vector<int> vec, int target){
        int left = 0, right = vec.size()-1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(vec[mid]==target) return mid;
            else if(vec[mid]<target) left = mid + 1;
            else if(vec[mid]>target) right = mid - 1;
        }
        return -1;
    }

    /*
    有序数组搜索目标值：二分查找
    由于是二维数组，所以需要在两个维度进行搜索，由于每行都是升序，且下一行的第一个数大于该行最后一个数,因此可以将问题转化为：
    1. 搜索第一列，判断目标值存在的情况下，应该属于哪一行（即查找目标值或小于且最接近目标值的值）；
    2. 找到目标值所在行后，简化问题为在升序的一维数组中查找目标值，使用标准二分查找方法即可；
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        如果数组为空，则返回false；
        */
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        /*
        定义vector存放第一列元素
        */
        vector<int> firstcol;
        int m = matrix.size();
        for(int i=0; i<m; i++){
            firstcol.push_back(matrix[i][0]);
        }
        /*
        找到对应行
        */
        int col = searchCol(firstcol, target);
        cout<<col<<endl;
        /*
        在该行中找target
        */
        int row = searchTarget(matrix[col], target);
        cout<<row<<endl;
        return true ? row!=-1 : false;
    }
};

//方法2
class Solution {
public:
    /*
    将二维数组拉伸为一位数组进行搜索，其中，一位数组中matrix[mid]在二维数组中的位置为matrix[mid/row][mid%row]
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        int col = matrix.size(), row = matrix[0].size();
        int left = 0, right = col * row - 1;
        while(right>=left){
            int mid = left + (right - left) / 2;
            if(matrix[mid/row][mid%row]==target) return true;
            else if(matrix[mid/row][mid%row]<target) left = mid + 1;
            else if(matrix[mid/row][mid%row]>target) right = mid - 1;
        }
        return false;
    }
};