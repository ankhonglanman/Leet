impl Solution {
    pub fn find_the_distance_value(arr1: Vec<i32>, arr2: Vec<i32>, d: i32) -> i32 {
        let mut res: i32 = 0; 
        for i in 0..arr1.len() {
            let mut isValid: bool = true;
            for j in 0..arr2.len() {
                let diff: i32 = arr1[i] - arr2[j];
                if diff.abs() <= d {
                    isValid = false;
                    break;
                }
            }
            if isValid { 
                res += 1;
            }
        }
        res
    }
}