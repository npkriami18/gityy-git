#include <bits/stdc++.h>
using namespace std;

class DocumentElement{
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement {
private:
    string text;
public:
    TextElement(string text) {
        this->text = text;
    }
    string render() override {
        return text + "\n";
    }
};

class ImageElement : public DocumentElement {
private:
    string imagePath;
public:
    ImageElement(string imagePath) {
        this->imagePath = imagePath;
    }
    string render() override {
        return "[Image: " + imagePath + "]" + "\n";
    }
};

class Document {
private:
    vector<DocumentElement*> documentElements;
public:
    void addElement(DocumentElement* element){
        documentElements.push_back(element);
    }

    string render(){
        string result;
        for(auto element : documentElements) {
            result += element->render();
        }
        return result;
    }
};

class Persistence {
public:
    virtual void save(string data) = 0;
};

class SaveToFile : public Persistence{
public:
    void save(string data) override {
        ofstream outFile("document.txt");
        if(outFile){
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error: unable to openfile for writing." << endl;
        }
    }

};
class SaveToDB : public Persistence {
    void save(string data) override {
        cout << "Document saved to DB" << endl;
    }
};

class DocumentEditor {
private:
    Document* document;
    Persistence* storage;
    string renderedDocument;

public:
    DocumentEditor(Document* document, Persistence* storage) {
        this->document = document;
        this->storage = storage;
        this->renderedDocument = "";
    }

    void addText(string text) {
        document->addElement(new TextElement(text));
    }
    
    void addImage(string imagePath) {
        document->addElement(new ImageElement(imagePath));
    }

    string renderDocument(){
        renderedDocument = document->render();
        return renderedDocument;
    }

    void saveDocument(){
        storage->save(renderedDocument);
    }
};

int main(){

    Document* document = new Document();
    Persistence* persistence = new SaveToFile();
    DocumentEditor* editor = new DocumentEditor(document, persistence);

    editor->addText("hello world!");
    editor->addText("This is a real world document editor example.");
    editor->addImage("design.jpg");

    cout << editor->renderDocument() << endl;

    editor->saveDocument();

    return 0;
    
}

