##問題

下記の3ファイルを思うがままにリファクタリングしてみて下さい。

言語は問わない

```java
public class Main {
   public static void main(String[] args) {
       Person[] people = {
           new Person(new Label("Alice"), new Label("alice@example.com")),
           new Person(new Label("Bobby"), new Label("bobby@example.com")),
           new Person(new Label("Chris")),
       };
       for (Person p : people) {
           System.out.println(p.toString());
           p.display();
           System.out.println("");
       }
   }
}
```

```java
public class Label {
   private final String _label;
   public Label(String label) {
       _label = label;
   }
   public void display() {
       System.out.println("display: " + _label);
   }
   public String toString() {
       return "\"" + _label + "\"";
   }
}
```

```java
public class Person {
   private final Label _name;
   private final Label _mail;
   public Person(Label name, Label mail) {
       _name = name;
       _mail = mail;
   }
   public Person(Label name) {
       this(name, null);
   }
   public void display() {
       if (_name != null) {
           _name.display();
       }
       if (_mail != null) {
           _mail.display();
       }
   }
   public String toString() {
       String result = "[ Person:";
       result += " name=";
       if (_name == null) {
           result += "\"(none)\"";
       } else {
           result += _name;
       }
       result += " mail=";
       if (_mail == null) {
           result += "\"(none)\"";
       } else {
           result += _mail;
       }
       result += " ]";
       return result;
   }
}
```