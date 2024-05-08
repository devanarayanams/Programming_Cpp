#include <iostream>
#include <string>

using namespace std;

// Enum for image types
enum class ImageType { JPEG, PNG, GIF };

// Enum for video types
enum class VideoType { MP3, MP4, AVI };

// Interface for media items
class MediaItem {
protected: // only class which inherits can access these members
    string name;
    string dateCreated;
    int size; // in bytes

public:
    MediaItem(const string& nameArg, const string& dateCreatedArg, int sizeArg)
        : name(nameArg), dateCreated(dateCreatedArg), size(sizeArg) {}

    virtual void displayInfo() const = 0; // derived class must provide its own implementation
    const string& getName() const {
        return name;
    }
    const string& getDateCreated() const {
        return dateCreated;
    }
    int getSize() const {
        return size;
    }

    virtual ~MediaItem() = default;
};

// Interface for sharing media
class MediaSharing {
public:
    virtual void share(const MediaItem& item) const = 0;
    virtual ~MediaSharing() = default;
};

// Class for images
class Image : public MediaItem {
private:
    ImageType type;

public:
    Image(const string& nameArg, const string& dateCreatedArg, int sizeArg, ImageType typeArg)
        : MediaItem(nameArg, dateCreatedArg, sizeArg), type(typeArg) {}

    void displayInfo() const {
        cout << "Image: " << getName() << " (" << getDateCreated() << "), Size: " << getSize() << " bytes" << endl;
    }
};

// Class for videos
class Video : public MediaItem {
private:
    VideoType type;

public:
    Video(const string& nameArg, const string& dateCreatedArg, int sizeArg, VideoType typeArg)
        : MediaItem(nameArg, dateCreatedArg, sizeArg), type(typeArg) {}

    void displayInfo() const {
        cout << "Video: " << getName() << " (" << getDateCreated() << "), Size: " << getSize() << " bytes" << endl;
    }
};

// Class for sharing media via Bluetooth
class BluetoothSharing : public MediaSharing {
public:
    void share(const MediaItem& item) const {
        cout << "Sharing via Bluetooth: " << item.getName() << endl;
    }
};

// Class for sharing media via WhatsApp
class WhatsAppSharing : public MediaSharing {
public:
    void share(const MediaItem& item) const {
        cout << "Sharing via WhatsApp: " << item.getName() << endl;
    }
};

// Class for sharing media via Email
class EmailSharing : public MediaSharing {
public:
    void share(const MediaItem& item) const {
        cout << "Sharing via Email: " << item.getName() << endl;
    }
};

// Class to manage the gallery
class GalleryManager {
private:
    static const int MAX_ITEMS = 10; // Max number of items in the gallery
    MediaItem* items[MAX_ITEMS]; // Array to hold pointers to MediaItem objects
    int itemCount; // Current number of items in the gallery

public:
    GalleryManager() : itemCount(0) {}

    ~GalleryManager() {
        for (int i = 0; i < itemCount; ++i) {
            delete items[i];
        }
    }

    // Method to add a new item to the gallery
    bool addItem(MediaItem* item) {
        if (itemCount < MAX_ITEMS) {       // Check if the gallery has space for new items
            items[itemCount++] = item;     // Add the new item to the items array and increment itemCount
            return true;                   // Return true to indicate successful addition
        }
        return false;                      // Return false if the gallery is full and the item cannot be added
    }


    // Method to display all items in the gallery
    void displayAll() const {
        for (int i = 0; i < itemCount; ++i) {
            items[i]->displayInfo();
        }
    }
};

// Main function
int main() {
    // Create media items
    Image image1("Image1", "2024-05-07", 1024, ImageType::JPEG);
    Video video1("Video1", "2024-05-07", 2048, VideoType::MP4);

    // Create sharing instances
    BluetoothSharing bluetoothSharing;
    WhatsAppSharing whatsAppSharing;
    EmailSharing emailSharing;

    // Share media items
    bluetoothSharing.share(image1);
    whatsAppSharing.share(video1);
    emailSharing.share(image1);

    // Create gallery manager
    GalleryManager galleryManager;
    galleryManager.addItem(&image1);
    galleryManager.addItem(&video1);
    galleryManager.displayAll();

    return 0;
}
