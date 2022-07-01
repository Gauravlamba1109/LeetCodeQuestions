for (auto &el: boxes) {
currBatch = min(el[0], truckSize);
truckSize -= currBatch;
res += currBatch * el[1];
if (!truckSize) break;
}
return res;
}
};
​
class Solution {
public int maximumUnits(int[][] boxTypes, int truckSize) {
Arrays.sort(boxTypes,(a,b)->Integer.compare(b[1],a[1]));
return maximumUnitsHelper(boxTypes, 0, truckSize, 0, 0);
}
// type: type of box to be considered
// tusf: total units so far
// tbsf: total box so far
public int maximumUnitsHelper(int[][] boxTypes, int type, int truckSize, int tusf, int tbsf){
if(type == boxTypes.length || tbsf == truckSize){
return tusf;
}
int boxes = boxTypes[type][0];
int boxesAllowed = truckSize - tbsf;
int units = boxTypes[type][1];
if(boxes <= boxesAllowed){
int tbunits = boxes * units;
return maximumUnitsHelper(boxTypes, type + 1, truckSize, tusf + tbunits, tbsf + boxes);
}
else{
int tbunits = boxesAllowed * units;
return maximumUnitsHelper(boxTypes, type + 1, truckSize, tusf + tbunits, tbsf + boxesAllowed);
}
}
}
```