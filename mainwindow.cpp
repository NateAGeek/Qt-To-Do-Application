#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    checked_color = QColor(0, 255, 0, 25);
    unchecked_color = QColor(255, 255, 255, 255);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_to_list_clicked()
{
    if(ui->item_text->text() != ""){
        QListWidgetItem* temp_check_list_item = new QListWidgetItem(ui->item_text->text());
        temp_check_list_item->setFlags(temp_check_list_item->flags() | Qt::ItemIsUserCheckable);
        temp_check_list_item->setCheckState(Qt::Unchecked);
        ui->list_items->insertItem(0, temp_check_list_item);
        ui->item_text->setText("");
    }
}

void MainWindow::on_list_items_itemChanged(QListWidgetItem *item)
{
    bool checked = item->checkState() == Qt::Checked;

    if(checked){
        int current_row = ui->list_items->row(item);
        ui->list_items->takeItem(current_row);
        item->setBackgroundColor(checked_color);
        ui->list_items->addItem(item);
    }else{
        int current_row = ui->list_items->row(item);
        ui->list_items->takeItem(current_row);
        item->setBackgroundColor(unchecked_color);
        ui->list_items->insertItem(0, item);
    }
}

void MainWindow::on_item_text_returnPressed()
{
    on_add_to_list_clicked();
}

void MainWindow::on_move_item_up_clicked()
{
    QList<QListWidgetItem*> items = ui->list_items->selectedItems();
    foreach (QListWidgetItem* item, items) {
        bool checked = item->checkState() == Qt::Checked;
        if(!checked){
            int current_row = ui->list_items->row(item);
            ui->list_items->takeItem(current_row);
            ui->list_items->insertItem(current_row-1, item);
            item->setSelected(true);
        }
    }
}

void MainWindow::on_move_item_down_clicked()
{
    QList<QListWidgetItem*> items = ui->list_items->selectedItems();
    foreach (QListWidgetItem* item, items) {
        bool checked = item->checkState() == Qt::Checked;
        if(!checked){
            int current_row = ui->list_items->row(item);
            ui->list_items->takeItem(current_row);
            ui->list_items->insertItem(current_row+1, item);
            item->setSelected(true);
        }
    }
}

void MainWindow::on_delete_item_clicked()
{
    QList<QListWidgetItem*> items = ui->list_items->selectedItems();
    foreach (QListWidgetItem* item, items) {
        int current_row = ui->list_items->row(item);
        QListWidgetItem* remove_item = ui->list_items->takeItem(current_row);
        delete remove_item;
    }
}
