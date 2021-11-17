#include "Types/InlineQueryResultCachedPhoto.h"

#include "Internal/ConversionFunctions.h"
#include "Types/InputMessageContent.h"

Telegram::InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto() :
	id(),
	photo_file_id(),
	title(),
	description(),
	caption(),
	parse_mode(),
	caption_entities(),
	reply_markup(),
	input_message_content()
{}

Telegram::InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto(const QString& id,
																	 const QString& photo_file_id,
																	 const std::optional<QString>& title,
																	 const std::optional<QString>& description,
																	 const std::optional<QString>& caption,
																	 const std::optional<QString>& parse_mode,
																	 const std::optional<QVector<MessageEntity>>& caption_entities,
																	 const std::optional<InlineKeyboardMarkup>& reply_markup,
																	 const std::optional<std::shared_ptr<InputMessageContent>>& input_message_content) :
	id(id),
	photo_file_id(photo_file_id),
	title(title),
	description(description),
	caption(caption),
	parse_mode(parse_mode),
	caption_entities(caption_entities),
	reply_markup(reply_markup),
	input_message_content(input_message_content)
{
}

QJsonObject Telegram::InlineQueryResultCachedPhoto::toObject() const
{
	if (isEmpty())
		return QJsonObject();

	QJsonObject inlineQueryResultCachedPhotoJsonObject{ {"type", type}, {"id", id}, {"photo_file_id", photo_file_id} };

	if (title.has_value())					inlineQueryResultCachedPhotoJsonObject.insert("title", *title);
	if (description.has_value())			inlineQueryResultCachedPhotoJsonObject.insert("description", *description);
	if (caption.has_value())				inlineQueryResultCachedPhotoJsonObject.insert("caption", *caption);
	if (parse_mode.has_value())				inlineQueryResultCachedPhotoJsonObject.insert("parse_mode", *parse_mode);
	if (caption_entities.has_value())		inlineQueryResultCachedPhotoJsonObject.insert("caption_entities", QVectorToQJsonArray(*caption_entities));
	if (reply_markup.has_value())			inlineQueryResultCachedPhotoJsonObject.insert("reply_markup", reply_markup->toObject());
	if (input_message_content.has_value())	inlineQueryResultCachedPhotoJsonObject.insert("input_message_content", (**input_message_content).toObject());

	return inlineQueryResultCachedPhotoJsonObject;
}

bool Telegram::InlineQueryResultCachedPhoto::isEmpty() const
{
	return id == ""
		   and photo_file_id == ""
		   and title == std::nullopt
		   and description == std::nullopt
		   and caption == std::nullopt
		   and parse_mode == std::nullopt
		   and caption_entities == std::nullopt
		   and reply_markup == std::nullopt
		   and input_message_content == std::nullopt;
}
