#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QColor>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_add_to_list_clicked();

    void on_list_items_itemChanged(QListWidgetItem *item);

    void on_item_text_returnPressed();

    void on_move_item_up_clicked();

    void on_move_item_down_clicked();

    void on_delete_item_clicked();

private:
    Ui::MainWindow *ui;
    QColor checked_color;
    QColor unchecked_color;
};

#endif // MAINWINDOW_H
