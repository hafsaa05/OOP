/*
 You are tasked with designing a simple social media platform that handles users, posts, and comments. 
 Users can create posts, comment on posts, and view their feed.
 1. User class: . Attributes: . userld (int): Unique identifier for the user. 
 . userName (string): Name of the user. . posts (array of Post objects): List of posts created by the user. 
 2. Post class: Attributes: . . postld (int): Unique identifier for the post. 
 content (string): Content of the post. comments (array of Comment objects): List of comments on the post. 
 3. Comment class: . Attributes: commentld (int): Unique identifier for the comment. 
 • content (string): Content of the comment. • author (pointer to User object): User who wrote the comment. 
 4. SocialMediaPlatform class: Tasks: • Attributes: . users (array of User objects): List of registered users. 
 TASKS:
 a) Implement the User, Post, Comment and SocialMediaPlatform classes with appropriate constructors. 
 b) Create a simple program to test the implemented classes. Write functions in the appropriate class to 
 perform these operations: i. Register a new user. ii. Create a new post. iii. Add a new comment to posts. 
 iv. Display the user feed (all the posts created by a given user).*/
#include <iostream>
#include <string>

using namespace std;

class User; // Forward declaration

class Comment {
private:
    static int nextCommentID;
    int commentID;
    string content;
    User* author;

public:
    Comment() : commentID(0), content(""), author(nullptr) {} // Default constructor

    Comment(string content, User* author) : content(content), author(author) {
        commentID = generateCommentID();
    }

    static int generateCommentID() {
        return nextCommentID++;
    }

    int getCommentID() const {
        return commentID;
    }

    string getContent() const {
        return content;
    }

    User* getAuthor() const {
        return author;
    }
};

int Comment::nextCommentID = 1;

class Post {
private:
    static int nextPostID;
    int postID;
    string content;
    Comment* comments;
    int maxComments;
    int numComments;

public:
    Post(string content, int maxComments) : content(content), maxComments(maxComments), numComments(0) {
        postID = generatePostID();
        comments = new Comment[maxComments]; // Allocate memory for comments
    }

    ~Post() {
        delete[] comments; // Deallocate memory for comments
    }

    static int generatePostID() {
        return nextPostID++;
    }

    int getPostID() const {
        return postID;
    }

    string getContent() const {
        return content;
    }

    void addComment(const Comment& comment) {
        if (numComments < maxComments) {
            comments[numComments++] = comment;
        } else {
            cout << "Maximum comments per post reached." << endl;
        }
    }
};

int Post::nextPostID = 1;

class User {
private:
    static int nextUserID;
    int userID;
    string userName;

public:
    User(string name) : userName(name) {
        userID = generateUserID();
    }

    static int generateUserID() {
        return nextUserID++;
    }

    int getUserID() const {
        return userID;
    }

    string getUserName() const {
        return userName;
    }
};

int User::nextUserID = 1;

int main() {
    User user("Alice");
    Post post("Hello, world!", 10);
    Comment comment("Nice post!", &user);

    post.addComment(comment);

    cout << "Post ID: " << post.getPostID() << endl;
    cout << "Content: " << post.getContent() << endl;

    cout << "Comments:" << endl;
    cout << "Comment ID: " << comment.getCommentID() << endl;
    cout << "Content: " << comment.getContent() << endl;
    cout << "Author: " << comment.getAuthor()->getUserName() << endl;

    return 0;
}
