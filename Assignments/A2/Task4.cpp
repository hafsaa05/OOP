#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Comment; 
class Post; 

class User {
protected: 
    string name, email, password;
public:
    User(string name, string email, string password) 
        : name(name), email(email), password(password) {}

    bool verifyUser(const User& user) { 
        return user.name == this->name && user.email == this->email && user.password == this->password; 
    }

    string getName() const { 
        return name; 
    }
    void setName(const string& newName) { 
        name = newName; 
    }

    string getEmail() const { 
        return email; 
    }
    void setEmail(const string& newEmail) { 
        email = newEmail; 
    }

    virtual ~User() {}

    // XOR Encryption Algorithm
    string passwordEncryption(string username, string password){
        string key = username;

        for(int i=0; i<password.length(); i++){ // XOREncryptDecrypt
            password[i] = password[i] ^ key[i % key.length()];
        }
        return password;
    }
};

class RegularUser : public User {
public:
    int feedSize;
    static const int MAX_FEED_SIZE = 10;
    Post* feed[MAX_FEED_SIZE];

    RegularUser(string username, string email, string password) : User(username, email, password), feedSize(0) {}

    void addToFeed(Post *fe){
        if(feedSize < MAX_FEED_SIZE){
            feed[feedSize] = fe;
            feedSize++;
        } else {
            cout << "Max post limit reached!"<< endl;
        }
    }

    void viewFeed();
};

class BusinessUser : public User {
public:
    int promotionLimit = 10;
    static int countpromote;

    BusinessUser(string username, string email, string password) : User(username, email, password) {}

    void promotePost(Post &post);

    bool verifyUser(string inputPassword); 

    bool checkPromotionLimit() {
        if (countpromote >= promotionLimit) {
            cout << "Maximum post limit reached!" << endl;
            return false;
        }
        countpromote++;
        return true;
    }
};

int BusinessUser::countpromote = 0;

class Post {
private:
    int postId, likes, views;
    string content;
    Comment* comments[10];
    int count;
    static int totalPosts;
public:
    Post(string content = "")
        : content(content), postId(totalPosts++), likes(0), count(0), views(0) {}

    int getID() const { return postId; }
    int getLikes() const { return likes; }
    int getViews() const { return views; }

    void setLikes(const int likes) { 
        this->likes = likes; 
    }
   
    void setViews(const int views) { 
        this->views = views;
    }
    void addComment(const Comment& comment) {
        if (count < 10) comments[count++] = const_cast<Comment*>(&comment); 
    }

    void display();
};

int Post::totalPosts = 0;

class Comment {
private:
    int commentId;
    string content;
    static int totalComments;
public:
    Comment(string content = "")
        : content(content), commentId(totalComments++) {}

    void display() { cout << "\t[" << commentId << "]: " << content << '\n'; }
};

int Comment::totalComments = 0;

void sortPosts(Post *posts, int count) {
    sort(posts, posts+count, [&](const Post& a, const Post& b) { return a.getLikes() > b.getLikes(); });
    sort(posts, posts+count, [&](const Post& a, const Post& b) { return a.getViews() > b.getViews(); });
}

void RegularUser::viewFeed() {
    for(int i = 0; i < feedSize; i++){
        feed[i]->display();
    }
}

void BusinessUser::promotePost(Post &post) {
    if (checkPromotionLimit()) {
        cout << "Your post is promoted" << endl;
        post.setLikes(post.getLikes() * 2); // Doubling likes
        post.setViews(post.getViews() * 3); // Tripling views
    }
}

bool BusinessUser::verifyUser(string inputPassword) {
    bool verified = inputPassword == password;
    cout << "User verification result: " << (verified ? "Verified" : "Not verified") << endl;
    return verified;
}

void Post::display() {
    cout << "[" << postId << "]: " << content << '\n';
    cout << "Likes: " << likes << '\n';
    cout << "Views: " << views << '\n';
    cout << "Comments: " << count << '\n';
    for (int i = 0; i < count; i++)
        comments[i]->display();
    cout << endl;
}

int main() {
    cout<<"Name: Hafsa Rashid"<<endl<<"Student ID: 23K-0064"<<endl;
    cout<<"\n";
    RegularUser regularUser("u1", "u1@example.com", "password1");
    BusinessUser businessUser("business", "business@example.com", "password2");

    User user1("u1", "u1@example.com", "password1");

    
    cout << "User 1 verified: " << regularUser.verifyUser(user1) << endl;
    cout << "User 2 verified: " << businessUser.verifyUser("password2") << endl;

    
    Post post1("What a beautiful day!");
    Post post2("Just finished a great book!");
    Post post3("Excited for the weekend!");
    
    regularUser.addToFeed(&post1);
    regularUser.addToFeed(&post2);
    regularUser.addToFeed(&post3);

    
    regularUser.viewFeed();

    post3.setLikes(1);
    post3.setViews(1); 
    post3.display();
    businessUser.promotePost(post3);
    post2.display();

    return 0;
}
