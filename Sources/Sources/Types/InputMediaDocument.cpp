#include "Types/InputMediaDocument.h"

#include "Internal/Utility/QJsonArrayInserter.h"
#include "Internal/Utility/QVectorInserter.h"

Telegram::InputMediaDocument::InputMediaDocument() :
	media(),
	thumb(),
	caption(),
	parse_mode(),
	caption_entities(),
	disable_content_type_detection()
{}

Telegram::InputMediaDocument::InputMediaDocument(const std::variant<QFile*, QString>& media,
												 const std::optional<std::variant<QFile*, QString>>& thumb,
												 const std::optional<QString>& caption,
												 const std::optional<QString>& parse_mode,
												 const std::optional<QVector<MessageEntity>>& caption_entities,
												 const std::optional<bool>& disable_content_type_detection) :
	media(media),
	thumb(thumb),
	caption(caption),
	parse_mode(parse_mode),
	caption_entities(caption_entities),
	disable_content_type_detection(disable_content_type_detection)
{}

Telegram::InputMediaDocument::InputMediaDocument(const QJsonObject& json_object) {
	json_object.contains("media")							? media = json_object["media"].toString()															: media = nullptr;
	json_object.contains("thumb")							? thumb = json_object["thumb"].toString()															: thumb = std::nullopt;
	json_object.contains("caption")							? caption = json_object["caption"].toString()														: caption = std::nullopt;
	json_object.contains("parse_mode")						? parse_mode = json_object["parse_mode"].toString()													: parse_mode = std::nullopt;
	json_object.contains("caption_entities")				? caption_entities = Utility::QVectorInserter<MessageEntity>::make(json_object["caption_entities"].toArray())	: caption_entities = std::nullopt;
	json_object.contains("disable_content_type_detection")	? disable_content_type_detection = json_object["disable_content_type_detection"].toBool()			: disable_content_type_detection = std::nullopt;
}

QJsonObject Telegram::InputMediaDocument::toObject() const {
	if (isEmpty()) return {};

	QJsonObject input_media_document_json_object{ {"type", QString(QMetaEnum::fromType<decltype(type)>().valueToKey(static_cast<int>(type))).toLower()} };

	if (std::holds_alternative<QFile*>(media))  input_media_document_json_object.insert("media", QString("attach://%1").arg(std::get<QFile*>(media)->fileName()));
	if (std::holds_alternative<QString>(media)) input_media_document_json_object.insert("media", std::get<QString>(media));

	if (thumb.has_value())
	{
		if (std::holds_alternative<QFile*>(*thumb))  input_media_document_json_object.insert("thumb", QString("attach://%1").arg(std::get<QFile*>(*thumb)->fileName()));
		if (std::holds_alternative<QString>(*thumb)) input_media_document_json_object.insert("thumb", std::get<QString>(*thumb));
	}

	if (caption.has_value())							input_media_document_json_object.insert("caption", *caption);
	if (parse_mode.has_value())							input_media_document_json_object.insert("parse_mode", *parse_mode);
	if (caption_entities.has_value())					input_media_document_json_object.insert("caption_entities", Utility::QJsonArrayInserter::make(*caption_entities));
	if (disable_content_type_detection.has_value())		input_media_document_json_object.insert("disable_content_type_detection", *disable_content_type_detection);

	return input_media_document_json_object;
}

bool Telegram::InputMediaDocument::isEmpty() const {
	bool contains_media(false);
	if (std::holds_alternative<QFile*>(media))
		if (std::get<QFile*>(media) != nullptr) contains_media = true;

	if (std::holds_alternative<QString>(media))
		if (std::get<QString>(media) != "") contains_media = true;

	return contains_media == false
		   and thumb == std::nullopt
		   and caption == std::nullopt
		   and parse_mode == std::nullopt
		   and caption_entities == std::nullopt
		   and disable_content_type_detection == std::nullopt;
}

Telegram::InputMedia::Type Telegram::InputMediaDocument::getType() const {
	return type;
}
