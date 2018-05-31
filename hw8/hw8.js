let contacts = [];
let table = document.getElementById("mytable")

function printtable(item) {
    var data = new Array();
    //table.innerHTML = "";
    data.push('<table id="mytable" width=60% border="1" align=center><caption>通訊錄</caption><tbody>');
    data.push('<tr align=center><td width=20%>學號</td><td width=25%>姓名</td><td width=25%>電話</td><td width=30%>信箱</td></tr>')
    for (var i = 0; i < item.length; i++) {
        data.push('<tr align=center>');
        data.push('<td>' + item[i].id + '</td>');
        data.push('<td>' + item[i].name + '</td>');
        data.push('<td>' + item[i].phone + '</td>');
        data.push('<td>' + item[i].mail + '</td>');
        data.push('</tr>');
    }
    data.push('</tbody></table>');
    document.getElementById("mytable").innerHTML = data.join('');
}

function insert(form) {
    let data = {
        id: form.uid.value,
        name: form.uname.value,
        phone: form.uphone.value,
        mail: form.umail.value,
    };
    if (myalert(data) != 1)
        return;
    if (searchid(data.id) != -1) {
        alert("Insert Error! 此學號已存在!");
        return;
    }
    contacts.push(data);
    printtable(contacts);
}

function mydelete(form) {
    let id = form.uid.value;
    let i = searchid(id);
    if (id === "") {
        printalert("學號");
        return;
    }
    if (i == -1) {
        alert("Delete Error! 此學號不存在!");
        return;
    }
    contacts.splice(i, 1);
    printtable(contacts);
    console.log("delete successful!");
}

function update(form) {
    let data = {
        id: form.uid.value,
        name: form.uname.value,
        phone: form.uphone.value,
        mail: form.umail.value,
    };
    let i = searchid(data.id);
    if (myalert(data) != 1)
        return;
    if (i == -1) {
        alert("Update Error! 此學號不存在!");
        return;
    }
    contacts[i].id = data.id;
    contacts[i].name = data.name;
    contacts[i].phone = data.phone;
    contacts[i].mail = data.mail;
    printtable(contacts);
    console.log("update successful!");
}

function mylist() {
    printtable(contacts);
    console.log("list successful!");
}

function search(word) {
    let comp = [];
    if (word === "") {
        alert("搜尋欄為必填欄位");
        return;
    }
    for (let i = 0; i < contacts.length; i++) {
        if (contacts[i].id.indexOf(word) != -1)
            comp.push(contacts[i]);
        else if (contacts[i].name.indexOf(word) != -1)
            comp.push(contacts[i]);
        else if (contacts[i].phone.indexOf(word) != -1)
            comp.push(contacts[i]);
        else if (contacts[i].mail.indexOf(word) != -1)
            comp.push(contacts[i]);
    }
    if (comp.length === 0) {
        alert("No Match!");
        printtable(contacts);
        return;
    }
    printtable(comp)
    console.log("search successful!");
}

function myalert(data) {
    let item = "";
    if (data.id === "")
        item += "學號\n";
    if (data.name === "")
        item += "姓名\n";
    if (data.phone === "")
        item += "電話\n";
    if (data.mail === "")
        item += "信箱\n";
    if (item === "")
        return 1;
    printalert(item);
}

function printalert(item) {
    alert(item + "=>為必填欄位!");
}

function searchid(id) {
    for (let i = 0; i < contacts.length; i++) {
        if (contacts[i].id == id)
            return i;
    }
    return -1;
}