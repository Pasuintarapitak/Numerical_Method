const math = require('mathjs');
const n = 9;
const x = [10, 15, 20, 30, 40, 50, 60, 70, 80];
const fx = [5, 9, 15, 18, 22, 30, 35, 38, 43];


function sumFunc(row, col) {
    let total = 0;
    if (row === 0 && col === 0) {
        return n;
    } else {
        for (let i = 0; i < n; i++) {
            total += Math.pow(x[i], row + col);
        }
        return total;
    }
}

function findDet(col,order,m,b) {
    let temp = Array.from({ length: order+1 }, () => Array(order+1).fill(0));
    for(let i = 0 ; i < order+1 ; i++){
        for(let j = 0 ; j <order+1 ; j++){
            if(j == col){
                temp[i][j] = b[i];
            }
            else{
                temp[i][j] = m[i][j];
            }
        }
    }
    // console.log(temp);
    
    return math.det(temp);
}

    const readline = require('readline');
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.question("Enter the order of the polynomial: ", (input) => {
        const order = parseInt(input, 10);

        const m = Array.from({ length: order + 1 }, () => Array(order + 1).fill(0));
        const b = [];
        const a = [];
    
        //find Matrix
        for (let i = 0; i < order + 1; i++) {
            for (let j = 0; j < order + 1; j++) {
                m[i][j] = sumFunc(i, j);
            }
        }
        //find b
        for(let i = 0 ; i <order+1 ; i++){
            let sum = 0;
            for(let j = 0; j < n;j++){
                sum += math.pow(x[j],i) * fx[j];
            }
            b.push(sum);
        }    
        // console.log(b);
        
    


        const detM = math.det(m) // Find det
        if(detM === 0){
            console.error("Divide by zero");
            return;
        }
        for(let i = 0 ; i < order+1 ; i++){
            const detAi = findDet(i,order,m,b);
            const xi = detAi / detM;
            a.push(xi);
            // console.log(xi);
            
        }
        // console.log(a);
        
        let total = 0;
        let value = 65;
        for(let i = 0 ; i < order+1 ; i++){
            total+= a[i]*math.pow(value,i);
        }
        console.log(total);
        

        rl.close();
    });



