<html>
<head>
<title>Student Management System</title>
</head>
<body>
<button onclick="addstu()">Add</button><br>
<button onclick="viewstu()">view</button>
<script>
var em_module = require('./stu.js');
var rno=new Array(20);
var name=new Array(20);
var mark=new Array(20);
var ns=0;
var n=prompt("Enter number of student");
for(j=0;j<n;j++)
    {
       mark[i]=new Array(3)
     }
for(int i=0;i<n;i++)
{
    rno[i] = prompt("Enter rollno");
    name[i] = prompt("Enter name");
    for(int j=0;j<3;j++)
    {
       mark[i][j] = prompt("Subject "+j+"mark :"); 
     }
}
/*var ns=em_module._add(); // direct calling works
em_module.ccall("add"); // using ccall etc. also work
console.log(em_module._view(ns,rno)); // values can be returned, etc.*/

</script>

</body>
</html>
