#include "Types/InlineQueryResultCachedGif.h"

#include "Internal/ConversionFunctions.h"

Telegram::InlineQueryResultCachedGif::InlineQueryResultCachedGif() : 
	id(),
	gif_file_id(),
	title(),
	caption(),
	parse_mode(),
	caption_entities(),
	reply_markup(),
	input_message_content()
{}

Telegram::InlineQueryResultCachedGif::InlineQueryResultCachedGif(const QString& id,
																 const QString& gif_file_id,
																 const std::optional<QString>& title,
																 const std::optional<QString>& caption,
																 const std::optional<QString>& parse_mode,
																 const std::optional<QVector<MessageEntity>>& caption_entities,
																 const std::optional<InlineKeyboardMarkup>& reply_markup,
																 const std::optional<std::shared_ptr<InputMessageContent>>& input_message_content) :
	id(id),
	gif_file_id(gif_file_id),
	title(title),
	caption(caption),
	parse_mode(parse_mode),
	caption_entities(caption_entities),
	reply_markup(reply_markup),
	input_message_content(input_message_content)
{}

QJsonObject Telegram::InlineQueryResultCachedGif::toObject() const {
	if (isEmpty()) return {};

	QJsonObject inline_query_result_cached_gif_json_object{ {"type", QString(QMetaEnum::fromType<decltype(type)>().valueToKey(static_cast<int>(type))).toLower()}, {"id", id}, {"gif_file_id", gif_file_id} };

	if (title.has_value())					inline_query_result_cached_gif_json_object.insert("title", *title);
	if (caption.has_value())				inline_query_result_cached_gif_json_object.insert("caption", *caption);
	if (parse_mode.has_value())				inline_query_result_cached_gif_json_object.insert("parse_mode", *parse_mode);
	if (caption_entities.has_value())		inline_query_result_cached_gif_json_object.insert("caption_entities", QVectorToQJsonArray(*caption_entities));
	if (reply_markup.has_value())			inline_query_result_cached_gif_json_object.insert("reply_markup", reply_markup->toObject());
	if (input_message_content.has_value())	inline_query_result_cached_gif_json_object.insert("input_message_content", (**input_message_content).toObject());

	return inline_query_result_cached_gif_json_object;
}

bool Telegram::InlineQueryResultCachedGif::isEmpty() const {
	return id == ""
		and gif_file_id == ""
		and title == std::nullopt
		and caption == std::nullopt
		and parse_mode == std::nullopt
		and caption_entities == std::nullopt
		and reply_markup == std::nullopt
		and input_message_content == std::nullopt;
}

Telegram::InlineQueryResult::Type Telegram::InlineQueryResultCachedGif::getType() const {
	return type;
}
