let arr = [23,15,76,54,54];
let max = Math.max(...arr)
console.log(max)

let freq = new Array(max+1).fill(0);


arr.forEach((item) => {
    freq[item] +=1;
})

freq.forEach((item,index)=>{
    if(item>0){
        console.log("The element " + index + " is repeated "+ item + " times")
    }
})
