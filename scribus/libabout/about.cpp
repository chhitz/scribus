#include "about.h"
#include "about.moc"
#include <qpixmap.h>

#if (_MSC_VER >=1200)
 #include "win-config.h"
#else
 #include "config.h"
#endif

extern QPixmap loadIcon(QString nam);

extern "C" void* Run(QWidget *d);

/*!
 \fn void* Run(QWidget *d)
 \author Franz Schmid
 \date  
 \brief Creates About dialog and returns pointer to it
 \param d QWidget pointer to About dialog widget
 \retval dia returned widget pointer
 */
void* Run(QWidget *d)
{
	About *dia = new About(d);
	return dia;
}

/*!
 \fn About::About( QWidget* parent )
 \author Franz Schmid 
 \date  
 \brief Constructor for About dialog box
 \param parent QWidget pointer to parent window
 \retval About dialog
 */
About::About( QWidget* parent )
		: QDialog( parent, "About", true, 0 )
{
	setCaption( tr("About Scribus%1%2").arg(" ").arg(VERSION) );
	setIcon(loadIcon("AppIcon.png"));
	AboutLayout = new QVBoxLayout( this );
	AboutLayout->setSpacing( 6 );
	AboutLayout->setMargin( 10 );
	TabWidget2 = new QTabWidget( this, "TabWidget2" );
	TabWidget2->setMinimumSize( QSize( 438, 258 ) );
	tab = new QWidget( TabWidget2, "tab" );
	tabLayout1 = new QVBoxLayout( tab );
	tabLayout1->setSpacing( 6 );
	tabLayout1->setMargin( 15 );
	PixmapLabel1 = new QLabel( tab, "PixmapLabel1" );
	PixmapLabel1->setPixmap(loadIcon("scribus_logo.jpg"));
	PixmapLabel1->setAlignment(Qt::AlignCenter);
	tabLayout1->addWidget( PixmapLabel1 );
	BuildID = new QLabel( tab, "BB" );
	BuildID->setAlignment(Qt::AlignCenter);
	QString bu = tr("%1. %2 %3 ").arg(03).arg("March").arg(2004);
#ifdef HAVE_CMS
	bu += "C";
#else
	bu += "*";
#endif
	bu += "-";
#ifdef HAVE_CUPS
	bu += "C";
#else
	bu += "*";
#endif
	bu += "-";
#ifdef HAVE_TIFF
	bu += "T";
#else
	bu += "*";
#endif

	BuildID->setText( tr("Scribus Version %1\n%2 %3").arg(VERSION).arg( tr("Build-ID:")).arg(bu));
	tabLayout1->addWidget( BuildID );
	TabWidget2->insertTab( tab, tr( "About" ) );
	tab_2 = new QWidget( TabWidget2, "tab_2" );
	tabLayout = new QHBoxLayout( tab_2 );
	tabLayout->setSpacing( 6 );
	tabLayout->setMargin( 10 );
	TextView1 = new QTextView( tab_2, "TextView1" );
	TextView1->setText(QString::fromUtf8("<table><tr><td><b>" + tr("Programming:").utf8() + "</b></td><td> </td></tr>" +
	                                     "<tr><td>Franz Schmid</td><td>Franz.Schmid@altmuehlnet.de</td></tr>" +
	                                     "<tr><td>Paul F. Johnson</td><td>paul@all-the-johnsons.co.uk</td></tr>" +
	                                     "<tr><td>Craig Bradney</td><td>cbradney@zip.com.au</td></tr>" +
	                                     "<tr><td>Petr Vaněk</td><td>subzero@py.cz</td></tr>" +
	                                     "<tr><td> </td><td> </td></tr>" +
	                                     "<tr><td><b>" + tr("Contributions from:").utf8()  + "</b></td><td></td></tr>" +
	                                     "<tr><td>Alessandro Rimoldi</td><td>http://ideale.ch/contact</td></tr>" +
	                                     "<tr><td>Jean-Jacques Sarton</td><td>jj.sarton@t-online.de</td></tr>" +
	                                     "<tr><td>Christian Töpp</td><td>mr-ct@gmx.de</td></tr>" +
	                                     "<tr><td>Alastair Robinson</td><td>blackfive@fakenhamweb.co.uk</td></tr>" +
	                                     "<tr><td></td><td> </td></tr>" +
#if (_MSC_VER >= 1200)
	                                     "<tr><td><b>" + tr("Windows port:").utf8()  + "</b></td><td> </td></tr>" +
	                                     "<tr><td>Paul F. Johnson</td><td>paul@all-the-johnsons.co.uk</td></tr>" +
	                                     "<tr><td> </td><td> </td></tr>" +
#endif
	                                     "<tr><td><b>" + tr("Documentation:").utf8()  + "</b></td><td></td></tr>" +
	                                     "<tr><td>Peter Linnell</td><td>scribusdocs@atlantictechsolutions.com</td></tr>" +
	                                     "<tr><td>Yves Ceccone</td><td>yves@yeccoe.org</td></tr>" +
	                                     "<tr><td>Holger Reibold</td><td>http://www.bomots.de/scribus/</td></tr>" +
	                                     "<tr><td>Thomas Zastrow</td><td>webmaster@thomas-zastrow.de</td></tr></table>"));
	TextView1->setTextFormat( QTextView::RichText );
	tabLayout->addWidget( TextView1 );
	TabWidget2->insertTab( tab_2, tr( "Authors" ) );
	tab_3 = new QWidget( TabWidget2, "tab_3" );
	tabLayout_2 = new QHBoxLayout( tab_3 );
	tabLayout_2->setSpacing( 6 );
	tabLayout_2->setMargin( 10 );
	TextView2 = new QTextView( tab_3, "TextView1_2" );
	TextView2->setText(QString::fromUtf8( "<table><tr><td><b>" + tr("German:").utf8()  + "</b></td><td> </td></tr>" +
	                                      "<tr><td>Franz Schmid</td><td>Franz.Schmid@altmuehlnet.de</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("French:").utf8()  + "</b></td><td> </td>" +
	                                      "<tr><td>Michel Briand</td><td>michelbriand@free.fr</td></tr>" +
	                                      "<tr><td>Yves Ceccone</td><td>yves@yeccoe.org</td></tr>" +
	                                      "<tr><td>Nicolas Boos</td><td>nicolas.boos@wanadoo.fr</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Spanish and Catalan:").utf8()  + "</b></td><td> </td></tr>" +
	                                      "<tr><td>Josep Febrer</td><td>josep@linuxmail.org</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Italian:").utf8()  + "</b></td><td> </td></tr>" +
	                                      "<tr><td>Giovanni Biczó</td><td>gbiczo@freestart.hu</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Hungarian:").utf8()  + "</b></td><td> </td></tr>" +
	                                      "<tr><td>Giovanni Biczó</td><td>gbiczo@freestart.hu</td></tr>" +
	                                      "<tr><td>Bence Nagy</td><td>scribus@tipogral.hu</td></tr>" +
	                                      "<tr><td>Zoltán Böszörményi</td><td>zboszor@freemail.hu</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Ukrainian:").utf8()  + "</b></td><td> </td></tr>" +
	                                      "<tr><td>Sergiy Kudryk</td><td>kudryk@yahoo.com</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Bulgarian:").utf8()  + "</b></td><td> </td></tr>" +
	                                      "<tr><td>Vasko Tomanov</td><td>vasko@web.bg</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Galician:").utf8()  + "</b></td><td> </td></tr>" +
	                                      "<tr><td>Manuel Anxo Rei</td><td>manxopar@avogaciagalega.org</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Turkish:").utf8()  + "</b></td><td> </td></tr>" +
	                                      "<tr><td>Erkan Kaplan</td><td>Selamsana@uni.de</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Lithuanian:").utf8()  + "</b></td><td> </td></tr>" +
	                                      "<tr><td>Oleksandr Moskalenko</td><td>malex@purdue.edu</td></tr>" +
	                                      "<tr><td>Aivaras Kirejevas</td><td>kiras@mail.lt</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Polish:").utf8()  + "</b></td><td> </td></tr>" +
	                                      "<tr><td>Maciej Hański</td><td>m.hanski@gmx.at</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Czech:").utf8()  + "</b></td><td></td></tr>" +
	                                      "<tr><td>Petr Vaněk</td><td>subzero@py.cz</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Slovak:").utf8()  + "</b></td><td></td></tr>" +
	                                      "<tr><td>Zdenko Podobn&yacute;ý</td><td>zdpo@mailbox.sk</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Danish:").utf8()  + "</b></td><td></td></tr>" +
	                                      "<tr><td>Morten Langlo</td><td>mlanglo@post6.tele.dk</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Norwegian:").utf8()  + "</b></td><td></td></tr>" +
	                                      "<tr><td>Klaus Ade Johnstad</td><td>klaus@astro.uio.no</td></tr>" +
	                                      "<tr><td>Johannes Wilm</td><td>j@indymedia.no</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("English:").utf8()  + "</b></td><td></td></tr>" +
	                                      "<tr><td>Paul F. Johnson</td><td>paul@all-the-johnsons.co.uk</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Welsh:").utf8()  + "</b></td><td></td></tr>" +
	                                      "<tr><td>Kevin Donnelly</td><td>kevin@dotmon.com</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Russian:").utf8()  + "</b></td><td></td></tr>" +
	                                      "<tr><td>Alexandre Prokoudine</td><td>techwriter@land.ru</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Brazilian:").utf8()  + "</b></td><td></td></tr>" +
	                                      "<tr><td>Celio Santos</td><td>celio@electronic.srv.br</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "<tr><td><b>" + tr("Finnish:").utf8()  + "</b></td><td></td></tr>" +
	                                      "<tr><td>Riku Leino</td><td>tsoots@welho.com</td></tr>" +
	                                      "<tr><td> </td><td> </td></tr>" +
	                                      "</table>"));
	TextView2->setTextFormat( QTextView::RichText );
	tabLayout_2->addWidget( TextView2 );
	TabWidget2->insertTab( tab_3, tr( "Translations" ) );
	AboutLayout->addWidget( TabWidget2 );
	Layout2 = new QHBoxLayout;
	Layout2->setSpacing( 6 );
	Layout2->setMargin( 0 );
	QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
	Layout2->addItem( spacer );
	PushButton1 = new QPushButton( this, "PushButton1" );
	PushButton1->setText( tr( "Close" ) );
	PushButton1->setDefault( true );
	Layout2->addWidget( PushButton1 );
	AboutLayout->addLayout( Layout2 );
	setMaximumSize(sizeHint());

	// signals and slots connections
	connect( PushButton1, SIGNAL( clicked() ), this, SLOT( accept() ) );
}



