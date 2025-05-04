use std::collections::HashMap;
impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
         let mut map: HashMap<Vec<i32>, i32> = HashMap::new();
        for i in 0..dominoes.len() {
            if dominoes[i][0] > dominoes[i][1] {
                *map.entry(vec![dominoes[i][1], dominoes[i][0]]).or_insert(0) += 1;
            } else {
                *map.entry(vec![dominoes[i][0], dominoes[i][1]]).or_insert(0) += 1;
            }
        }
        map.values().map(|&count| count * (count - 1) / 2).sum()
    }
}