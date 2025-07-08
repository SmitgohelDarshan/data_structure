import java.util.Scanner;
class Song {
    String title;
    Song next;
    Song prev;

    Song(String title) {
        this.title = title;
        this.next = null;
        this.prev = null;
    }
}

public class MusicPlayer {
    static Song head = null, tail = null, current = null;

    public static void addSong(String title) {
        Song newSong = new Song(title);

        if (head == null) {
            head = tail = newSong;
        } else {
            tail.next = newSong;
            newSong.prev = tail;
            tail = newSong;
        }

        System.out.println("Added: " + title);
    }

    public static void playNext() {
        if (head == null) {
            System.out.println("Playlist is empty.");
            return;
        }

        if (current == null) {
            current = head;
        } else {
            current = (current.next != null) ? current.next : head;
        }

        System.out.println("Now Playing: " + current.title);
    }

    public static void playPrevious() {
        if (head == null) {
            System.out.println("Playlist is empty.");
            return;
        }

        if (current == null) {
            current = tail;
        } else {
            current = (current.prev != null) ? current.prev : tail;
        }

        System.out.println("Now Playing: " + current.title);
    }

    public static void showPlaylist() {
        if (head == null) {
            System.out.println("[Playlist is empty]");
            return;
        }

        System.out.println("── Playlist ──");
        Song temp = head;
        while (temp != null) {
            if (temp == current)
                System.out.println(temp.title + "  <-- playing");
            else
                System.out.println("   " + temp.title);
            temp = temp.next;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        while (true) {
            System.out.println("\n==== Music Player ====");
            System.out.println("1. Add Song");
            System.out.println("2. Play / Next Song");
            System.out.println("3. Previous Song");
            System.out.println("4. Show Playlist");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine(); 

            switch (choice) {
                case 1:
                    System.out.print("Enter song title: ");
                    String title = sc.nextLine();
                    addSong(title);
                    break;
                case 2:
                    playNext();
                    break;
                case 3:
                    playPrevious();
                    break;
                case 4:
                    showPlaylist();
                    break;
                case 0:
                    System.out.println("Goodbye!");
                    sc.close();
                    return;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
