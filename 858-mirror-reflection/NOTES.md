// pseudo code
function mirrorReflection(p,q) {
// reduce 2 from the equation
while (p%2==0 && q%2==0) {
p = p / 2
q = q / 2
}
// conclusion
if (p%2 == 0)
return 2
if (q%2 == 0)
return 0
return 1
}