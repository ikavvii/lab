const p1 = Promise.resolve(10);

const p2 = p1.then(value => {
    console.log(value);
    return value * 2;
}
)

// console.log(p2); // try me
p2.then(value => {
    console.log("Resolved value", value);
});