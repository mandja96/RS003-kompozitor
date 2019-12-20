#include "tracks_list_model.hpp"

int TracksListModel::rowCount(const QModelIndex &parent) const {
    return _data.size();
}

int TracksListModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

QHash<int, QByteArray> TracksListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TRACK_DATA] = "dataNotes";
    roles[TRACK_NUMBER] = "dataTrackNumber";
    roles[TRACK_TYPE] = "dataTrackType";
    return roles;
}

QVariant TracksListModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
        case TRACK_DATA:
            return QVariant::fromValue(_data[index.row()]);
        case TRACK_NUMBER:
            return QVariant::fromValue(index.row() + 1);
        case TRACK_TYPE:
            // Temporary value for testing
            return QVariant::fromValue(index.row() % 2);
        default:
            return QVariant();
    }
}