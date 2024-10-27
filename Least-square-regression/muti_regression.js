const math = require('mathjs');
const size = 4; 
const fx = [4, -5, -6, 0, -1, -7, -20]; 
const n = 7;
const x = [
    [1, 0, 2, 3, 4, 2, 1], 
    [0, 1, 4, 2, 1, 3, 6], 
    [1, 3, 1, 2, 5, 3, 4]  
];
let a = []; // Array for coefficients
let b = []; // Array for RHS of equations

function findDet(col){
    let temp = Array.from({ length: size }, () => Array(size).fill(0));
    for(let i = 0 ; i < size ; i++){
        for(let j = 0 ; j<size ; j++){
            if(j == col){
                temp[i][j] = b[i]
            }
            else{
                temp[i][j] = m[i][j]
            }
        }
    }
    // find det
    // console.log( math.det(temp));
    
    return math.det(temp)

}
function findSum(row, col) {
    let total = 0;
    if (row === 0 && col === 0) {
        return n; 
    }
    else if (row === 0) {
        for (let i = 0; i < n; i++) {
            total += x[col - 1][i]; 
        }
    }
    else if (col === 0) {
        for (let i = 0; i < n; i++) {
            total += x[row - 1][i]; 
        }
    } else {
        for (let i = 0; i < n; i++) {
            total += x[row - 1][i] * x[col - 1][i];
        }
    }
    return total;
}

// Main 
let m = Array.from({ length: size }, () => Array(size).fill(0));

for (let i = 0; i < size; i++) {
    for (let j = 0; j < size; j++) {
        m[i][j] = findSum(i, j);
    }
}

for (let i = 0; i < size; i++) {
    let sum = 0;
    for(let j = 0 ; j < n ; j++){
        if(i == 0){
            sum+= fx[j];
        }
        else{
            sum+= x[i-1][j] * fx[j];
        }
    }
    b.push(sum);
}

console.log('Matrix m:', m);
console.log('Matrix b:', b);

let detM = math.det(m);
// console.log(detM);

for (let i = 0; i < size; i++) {
    let ai = findDet(i) / detM;
    a.push(ai);
}
console.log(a);


