#include "Fiche_animal.h"
#include <QDebug>
#include <QMessageBox>
//#include "connection.h"



 bool ajouter();
 bool modifier();
 QSqlQueryModel * afficher();
 bool supprimer(int);
 int id,poid,taille,nbr_consultation,id_animal;
 QString date_vacc;

Fiche_animal::Fiche_animal()
{
   id=0;
   poid=0;
   taille=0;
   nbr_consultation=0;
   id_animal=0;
   date_vacc="";
}
 Fiche_animal::Fiche_animal(int id,int poid,int taille,int nbr_consultation,int id_animal ,QString date_vacc )
{
     this->id=id;
     this->poid=poid;
     this->taille=taille;
     this->nbr_consultation=nbr_consultation;
     this->id_animal=id_animal;
     this->date_vacc=date_vacc;

}

 bool Fiche_animal::ajouter()
 {


 QSqlQuery query;
 query.prepare("INSERT INTO FICHE_ANIMAL (ID, POID, TAILLE, NBR_CONSULTATION,DATE_VACC,ID_ANNIMAL) "
                     "VALUES (:ID, :POID, :TAILLE, :NBR_CONSULTATION,:DATE_VACC,:ID_ANNIMAL)");
 QString ID= QString::number(id);
 QString POID= QString::number(poid);
 QString TAILLE= QString::number(taille);
  QString NBR_CONSULTATION= QString::number(nbr_consultation);
   QString ID_ANNIMAL= QString::number(id_animal);
 query.bindValue(":ID", ID);
 query.bindValue(":POID", POID);
 query.bindValue(":TAILLE", TAILLE);
 query.bindValue(":NBR_CONSULTATION", NBR_CONSULTATION);
 query.bindValue(":DATE_VACC", date_vacc);
 query.bindValue(":ID_ANNIMAL", ID_ANNIMAL);

query.exec();


 return true    ;
 }

 QSqlQueryModel * Fiche_animal::afficher()
 {QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from FICHE_ANIMAL");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("POID"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("TAILLE"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("NBR_CONSULTATION"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_ANNIMAL"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_VACC"));

 return model;
 }






 bool Fiche_animal::modifier()
 {

 QSqlQuery query;

 query.prepare("UPDATE FICHE_ANIMAL SET POID=:POID,TAILLE=:TAILLE,NBR_CONSULTATION=:NBR_CONSULTATION,DATE_VACC=:DATE_VACC, ID_ANNIMAL=:ID_ANNIMAL WHERE ID=:ID");
 QString ID= QString::number(id);
 QString POID= QString::number(poid);
 QString TAILLE= QString::number(taille);
  QString NBR_CONSULTATION= QString::number(nbr_consultation);
   QString ID_ANNIMAL= QString::number(id_animal);
 query.bindValue(":ID", ID);
 query.bindValue(":POID", POID);
 query.bindValue(":TAILLE", TAILLE);
 query.bindValue(":NBR_CONSULTATION", NBR_CONSULTATION);
 query.bindValue(":DATE_VACC", date_vacc);
 query.bindValue(":ID_ANNIMAL", ID_ANNIMAL);

 return    query.exec();
 }




 bool Fiche_animal::supprimer(int NId)
 {
     QSqlQuery query;

     query.prepare("Delete from FICHE_ANIMAL where ID = :id");
     query.bindValue(":id",NId);
     return    query.exec();
 }
