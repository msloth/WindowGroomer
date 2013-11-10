#include "settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) : QDialog(parent)
{
  initWindow();

  QWidget::setFixedSize(sizeHint());
}

QSize SettingsWindow::sizeHint()
{
  return QSize(240, 320);
}

void SettingsWindow::initWindow()
{
  setWindowTitle(APP_PRODUCT " Preferences");

  // Set up OK/Apply/Cancel buttons
  QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok |
      QDialogButtonBox::Apply | QDialogButtonBox::Cancel);
  buttonBox->button(QDialogButtonBox::Ok)->setDefault(true);
  connect(buttonBox->button(QDialogButtonBox::Apply), SIGNAL(clicked()), this,
      SLOT(apply()));
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

  // General tab
  QWidget *generalTab = new QWidget(this);
  QFormLayout *generalPage = new QFormLayout(generalTab);
  verticalDivisions = new QSpinBox(generalTab);
  verticalDivisions->setRange(1, 32);
  generalPage->addRow(tr("Vertical divisions"), verticalDivisions);
  horizontalDivisions = new QSpinBox(generalTab);
  horizontalDivisions->setRange(1, 32);
  generalPage->addRow(tr("Horizontal divisions"), horizontalDivisions);

  // TODO(aarmea): More tabs for other functionality

  tabs = new QTabWidget(this);
  tabs->addTab(generalTab, tr("&General"));

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(tabs);
  layout->addWidget(buttonBox);
  setLayout(layout);
}
